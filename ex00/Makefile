src = main.cpp BitcoinExchange.cpp
cc = c++ -Wall -Wextra -Werror -std=c++98

btc = btc

all: btc

$(btc): $(src)
	@$(cc) $(src) -o btc
	@tput setaf 2; echo "btc IS READY"

clean:
	@rm -rf *.o
	@tput setaf 2; echo "CLEAN COMPLETE"

fclean: clean
	@rm -rf btc
	@tput setaf 2; echo "FCLEAN CLEAN"

re: clean fclean all

.PHONY: all clean fclean re