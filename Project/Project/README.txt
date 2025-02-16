


We will store pixels in a 2d array of structs that is dynamically allocated.




Unrelated Code:
(may or not run a game)
std::srand(std::time(0));
    int random = 0;
    random = std::rand() % 10 + 1;
    int guess = 0;

    std::cout << "Guess a number 1-10: ";
    std::cin >> guess;
    if (guess == random) std::cout << "Correct Guess!!!!!" << std::endl;
    else std::cout << "You stoopid" << std::endl;
    