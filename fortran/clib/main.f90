program callc
    integer :: a=5, b=2, output, add, subtract, multiply, err
    write(*, "(A)") "Fortran calling C"
    write(*, "(A,I0,A,I0)") "a=", a, ", b=", b
    err = add(a, b, output)
    write(*, "(I0)") output
    err = subtract(a, b, output)
    write(*, "(I0)") output
    output = multiply(a, b)
    write(*, "(I0)") multiply(a, b)
    write(*, "(F0.0)") divide(a, b)
end program callc