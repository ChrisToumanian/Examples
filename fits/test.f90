program test
    ! Create a FITS primary array containing a 2-D image
    integer status,unit,blocksize,bitpix,naxis,naxes(2)
    integer i,j,group,fpixel,nelements,array(300,200)
    character filename*80
    logical simple,extend
    status=0

    ! Name of the FITS file to be created:
    filename="outputfile.fits"

    ! Get an unused Logical Unit Number to use to create the FITS file
    call ffgiou(unit, status)
    write(*, "(I0)") unit
    write(*, "(I0)") status

end program test