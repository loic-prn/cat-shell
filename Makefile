all:
	@printf "[+] Compiling\n"
	@gcc src/*.c -o release/csh

run: all
	@printf "[+] Running\n"
	@./release/csh