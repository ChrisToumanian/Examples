program fitsreader

    integer status,unit,readwrite,blocksize,nkeys,nspace,hdutype,i,j
    character filename*80,record*80,arg*32,card*80,keyword*80,comment*80

    ! Get command line arguments
    call getarg(1, filename)
    call getarg(2, keyword)

    ! Open FITS file:
    Write(*, "(A)") "Opening FITS file..."
    Write(*, "(A)") ""
    status = 0
    call ftgiou(unit,status)
    readwrite = 0
    call ftopen(unit,filename,readwrite,blocksize,status)

    ! Get Key Value
    Write(*, "(A)") "Requesting keyword:"
    Write(*, "(A)") keyword
    call ftgcrd(unit, keyword, card, status)
    Write(*, "(A)") card
    Write(*, "(A)") ""

    j = 0
100 continue
    j = j + 1

    print *, "Header listing for sample.fits", j
    call ftghsp(unit,nkeys,nspace,status)

    ! Read each 80-character keyword record, and print it out.
    do i = 1, nkeys
        call ftgrec(unit,i,record,status)
        print *,record
    end do

    ! Print out an END record, and a blank line to mark the end of the header
    if (status .eq. 0) then
        print *, "END"
        print *, " "
    end if

    ! Try moving to the next extension in the FITS file, if it exists.
    call ftmrhd(unit,1,hdutype,status)

    if (status .eq. 0) then
        go to 100
    else if (status .eq. 107) then
        status = 0
    end if

    call ftclos(unit, status)
    call ftfiou(unit, status)

end program fitsreader