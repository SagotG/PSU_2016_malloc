The makefile generates a .so dynamic library. Use this library on linux or unix x86_64 system with LD_PRELOAD.

To generate librairy:

		make re
		make clean (clean *.o)
		make fclean (clean *.o and libmy_malloc.so)

To export library use:

		export LD_PRELOAD=$PWD/libmy_malloc.so

Reset by default malloc system:
		
		export LD_PRELOAD=
