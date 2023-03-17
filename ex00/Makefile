src = main.cpp BitcoinExchange.cpp
cc = c++ -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

Btc = Btc

all: Btc

$(Btc): $(src)
	@$(cc) $(src) -o Btc
	@tput setaf 2; echo "Btc IS READY"

clean:
	@rm -rf *.o
	@tput setaf 2; echo "CLEAN COMPLETE"

fclean: clean
	@rm -rf Btc
	@tput setaf 2; echo "FCLEAN CLEAN"

re: clean fclean all

.PHONY: all clean fclean re