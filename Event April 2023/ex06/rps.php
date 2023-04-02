<?php
$choices = array('rock', 'paper', 'scissors');
$computer_choice = $choices[rand(0,2)];

echo "Choose rock, paper, or scissors: ";
$user_choice = trim(fgets(STDIN));

if (!in_array($user_choice, $choices))
{
    echo "Invalid input. Please enter rock, paper, or scissors.\n";
    exit;
}

if ($user_choice == $computer_choice)
{
    echo "It's a tie!";
}
else if (($user_choice == 'rock' && $computer_choice == 'scissors') || ($user_choice == 'paper' && $computer_choice == 'rock') || ($user_choice == 'scissors' && $computer_choice == 'paper'))
{
    echo "Congratulations! You won!";
}
else
{
    echo "Sorry, you lost.";
}
echo " The computer chose $computer_choice.\n"
?>
