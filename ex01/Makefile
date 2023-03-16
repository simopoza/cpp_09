src = main.cpp RPN.cpp
cc = c++ -Wall -Wextra -Werror -std=c++98

RPN = RPN

all: RPN

$(RPN): $(src)
	@$(cc) $(src) -o RPN
	@tput setaf 2; echo "RPN IS READY"

clean:
	@rm -rf *.o
	@tput setaf 2; echo "CLEAN COMPLETE"

fclean: clean
	@rm -rf RPN
	@tput setaf 2; echo "FCLEAN CLEAN"

re: clean fclean all

.PHONY: all clean fclean re