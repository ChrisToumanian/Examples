function add(a, b)
	integer :: add
	integer :: a
	integer :: b
	add = a + b
	return
end function add

program Addition
	implicit none
	integer :: a
	integer :: b
	integer :: add
	print*, "Which two numbers would you like to add?"
	read (*,*) a,b
	print*, add(a,b)
end program Addition
