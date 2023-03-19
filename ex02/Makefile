src = main.cpp PmergeMe.cpp
cc = c++ -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

PmergeMe = PmergeMe

all: PmergeMe

$(PmergeMe): $(src)
	@$(cc) $(src) -o PmergeMe
	@tput setaf 2; echo "PmergeMe IS READY"

clean:
	@rm -rf *.o
	@tput setaf 2; echo "CLEAN COMPLETE"

fclean: clean
	@rm -rf PmergeMe
	@tput setaf 2; echo "FCLEAN CLEAN"

re: clean fclean all

.PHONY: all clean fclean re