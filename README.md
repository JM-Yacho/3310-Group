# CSE3310_S2018

All `git commands` can be found at https://confluence.atlassian.com/bitbucketserver/basic-git-commands-776639767.html

To begin a working local repository:

1. Clone the repository to a working directory.

2. Then use `git clone <url>`

3. Enter the directory and use `git init`


To add files you've been working on, on your local repository:

- Use `git add .` to add all changed files. The period means 'all'.

- `git commit -m "<msg>"` to solidify the changes.

- `git push origin <branch>` to send the changes to github (never the master branch).


List the files you've changed and those you still need to add or commit:

- `git status`

## Working in branches

We will never be working on the master branch to ensure our code's integrity.

- Create a new branch by using command `git checkout -b <branchname>`

- Switch between branches by using `git checkout <branchname>`

- Delete a branch with `git branch -D <branchname>`

