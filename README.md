# UberCasino
https://github.com/BudDavis/UberCasino

To build:

`% source ./release.bash` (be sure to change the OSPL_HOME path)  
`% make`

There are a couple of cpp defines that control debug
output:
    `DEBUG_PRINT` 

Set this in the makefile and recompile

Requirements:
---
This is a basic, minimal implementation of the blackjack game.
The players are stupid, and stop at 2 cards, the dealer has
a rigged deck and always deals a 10.
The exact requirements for the class assignment have not been implemented, but it should be close enough to get you started.

Source code:
---
This is a CLI based program, but note that it is event driven.

It should easily map to a gui callbacks

The main programs are **Dealer.cpp** and **Player.cpp**.

The top level classes are **dealer.cpp** and **player.cpp**.  All OpenSplice
I/O is done in **io.h**.  io.h is a generic, it is a bit ugly.

There is a home grown state machine implementation in dealer and player.
It will get way too unwieldy if additional functionality is added.  This
is crying out for additional abstractions.

Use Case:
---
1. The dealer starts and waits for the user to enter "start" at the command line.  
The dealer then sends out a Dealer struct.

2. The player starts. When it recieves a Dealer struct, it puts it in a list and displays the list.  Provided there is at least one dealer, the user can enter a number corresponding to the dealer.  When selected, the player will then send a Player structure, this is effectively asking if you can join the game.

3. The dealer waits until the first Player that matches his game_uuid is recieved.
At that point he starts a 20 second timer, and waits for others.  When a Player that matches is recieved, he inserts it into the Dealer and Publishes.

4. The timer expires, the dealer then starts to deal the cards. First, he deals himself two cards, one face down. For each player, he adds a card, increments the player idx, and waits for the player to respond with a Player record describing what it wants to do.

5. After all players have been dealt two cards, the dealer turns over his card, and the game exits.


# CSE3310_S2018

`git commands` can be found at: https://confluence.atlassian.com/bitbucketserver/basic-git-commands-776639767.html

`readme format` found here: https://help.github.com/articles/basic-writing-and-formatting-syntax/

## To begin a working local repository:

1. Clone the repository to a working directory.

2. Then use `git clone <url>`

3. Enter the directory and use `git init`


## To add files you've been working on to github

1. `git add .` to add all changed files. The period means 'all'.

2. `git commit -m "<msg>"` to solidify the changes.

3. `git pull` to update your branch with the master branch (you will still have your changes).

4. `git push origin <branch>` to send the changes to github (never the master branch).



## Working in branches

We will never be working on the master branch to ensure our code's integrity.

- **BEFORE CREATING A BRANCH**: Make sure your local repository is updated with the master branch.

	- switch to the master branch and use `git pull`

- **Create** a new branch by using command `git checkout -b <branchname>`

- **Switch** between branches by using `git checkout <branchname>`

- **Delete** a branch with `git branch -D <branchname>`

- **View** all branches type `git branch`

## Useful Commands:

`git status`

`git pull` is used to update your current HEAD branch with the latest changes from the remote server. This means that pull not only downloads new data; it also directly integrates it into your current working copy files. This has a couple of consequences:

Since `git pull` tries to merge remote changes with your local ones, a so-called "merge conflict" can occur. Check out our in-depth tutorial on How to deal with merge conflicts for more information.
Like for many other actions, it's highly recommended to start a "git pull" only with a clean working copy. This means that you should not have any uncommitted local changes before you pull. Use Git's Stash feature to save your local changes temporarily. (https://www.git-tower.com/learn/git/faq/difference-between-git-fetch-git-pull)
