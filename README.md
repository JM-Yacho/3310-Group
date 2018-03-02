# CSE3310_S2018

`git commands` can be found at https://confluence.atlassian.com/bitbucketserver/basic-git-commands-776639767.html

## To begin a working local repository:

1. Clone the repository to a working directory.

2. Then use `git clone <url>`

3. Enter the directory and use `git init`


## To add files you've been working on to github

- Use `git add .` to add all changed files. The period means 'all'.

- `git commit -m "<msg>"` to solidify the changes.

- `git pull` to update your branch with the master branch (you will still have your changes).

- `git push origin <branch>` to send the changes to github (never the master branch).



## Working in branches

We will never be working on the master branch to ensure our code's integrity.

- **BEFORE CREATING A BRANCH**: Make sure your local repository is updated with the master branch.

	- switch to the master branch and use `git pull`

- **Create** a new branch by using command `git checkout -b <branchname>`

- **Switch** between branches by using `git checkout <branchname>`

- **Delete** a branch with `git branch -D <branchname>`

## Useful Commands:

`git status`

`git pull` is used to update your current HEAD branch with the latest changes from the remote server. This means that pull not only downloads new data; it also directly integrates it into your current working copy files. This has a couple of consequences:

Since `git pull` tries to merge remote changes with your local ones, a so-called "merge conflict" can occur. Check out our in-depth tutorial on How to deal with merge conflicts for more information.
Like for many other actions, it's highly recommended to start a "git pull" only with a clean working copy. This means that you should not have any uncommitted local changes before you pull. Use Git's Stash feature to save your local changes temporarily. (https://www.git-tower.com/learn/git/faq/difference-between-git-fetch-git-pull)
