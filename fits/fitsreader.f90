program fitsreader

    integer status, unit, readwrite, blocksize, nkeys, nspace, hdutype, i, j, npixels
    integer*2 inarray(21)
    character filename*80, record*80, arg*32, card*80, keyword*80, comment*80
    character*1 binarray(21), bnul
    logical anynull

    ! Get command line arguments
    call getarg(1, filename)
    call getarg(2, keyword)
    if (filename .eq. "") then
        write(*, "(A)") "Please choose a file."
        go to 200
    end if

    ! Open FITS file:
    Write(*, "(A)") "Opening FITS file..."
    Write(*, "(A)") ""
    status = 0
    call ftgiou(unit, status)
    readwrite = 0
    call ftopen(unit, filename, readwrite, blocksize, status)

    ! Get Key Value
    if (keyword .ne. "") then
        Write(*, "(A)") "Requesting keyword:"
        Write(*, "(A)") keyword
        call ftgcrd(unit, keyword, card, status)
        Write(*, "(A)") card
        Write(*, "(A)") ""
    end if

    j = 0
100 continue
    j = j + 1

    print *, "Header listing for sample.fits", j
    call ftghsp(unit, nkeys, nspace, status)

    ! Read each 80-character keyword record, and print it out.
    do i = 1, nkeys
        call ftgrec(unit, i, record, status)
        print *,record
    end do

    ! Print out an END record, and a blank line to mark the end of the header
    if (status .eq. 0) then
        print *, "END"
        print *, " "
    end if

    ! Try moving to the next extension in the FITS file, if it exists.
    call ftmrhd(unit, 1, hdutype, status)

    if (status .eq. 0) then
        go to 100
    else if (status .eq. 107) then
        status = 0
    end if

    ! Read back binary array data
    anynull = .false.
    bnul = char(00)
    npixels = 2000

    ! Cffgsfb(fitsfile *fptr, int colnum, int naxis, long *naxes, long *blc, unsigned char *array, int *status)
    call ftgpvb(unit, 1, 1, 10, bnul, binarray, anynull, status)
    call ftgpvb(unit, 2, 1, 10, bnul, binarray, anynull, status)

    write(*, "(A)") "Binary Array:"
    do i = 1, npixels
	inarray(i) = ichar(binarray(i))
    end do

    write(*,1101) (inarray(i), i = 1, npixels), anynull,' (ftgpvb) '

1101 format(1x,20i3,l3,a)

    call ftclos(unit, status)
200 call ftfiou(unit, status)

end program fitsreader
