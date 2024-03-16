## Github workflow

0. Star the repository
![star the repo](https://i.ibb.co/4SyPpJ6/image.png)

1. Fork the repository
    - [Long variant](https://docs.github.com/en/get-started/quickstart/fork-a-repo)
    - Short variant
        1. Go to the repository's main page.
        2. Press the fork button.
        ![](https://i.ibb.co/QPDSCzm/image.png)
        3. Select a name of your new repository.
        4. Make sure to copy the main branch.
        5. Create the forked repo.
        ![](https://i.ibb.co/qBb95ff/image.png)

2. Set up git on your PC
    - Download git from [here](https://git-scm.com/downloads).
    - Install git through it's wizard and leave everything at default.
    - To make sure git is installed properly, run in a terminal the following command `git --version`.

3. Clone the repository on your local machine
    - [How to clone a repository.](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository)

4. Sync your repository with origin
    - In the terminal run the following command `git fetch origin`.
        - This will populate your local repository with the new branches.
    - After that run `git pull`.
        - This will pull all commits which have been uploaded to the remote repo.
    - Make sure to do this step every time before uploading a task to prevent conflicts.

5. Create a branch
    - You should create branch for each **task**.
    - The branch should be created from the master branch of the original repository. In this way you will always have the latest changes.
    - [About branches.](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-branches)
    - [How to create branch.](https://docs.github.com/en/desktop/contributing-and-collaborating-using-github-desktop/making-changes-in-a-branch/managing-branches#creating-a-branch)

6. Add a solution for a task
    - Create a folder for each task inside the **Solutions** folder for the week of which you want to add a task.
        - If the **Solutions** folder does not exist yet, create it yourself.
    - **The name of the folder should be TaskXX-FN where XX is the number of the task**<br> e.g. Task01-0MI0000000, Task12-0MI0000000 etc.
    - Copy your solution into the folder.

7. Commit solution to a task
    - After you have added all the files and made sure everything is named properly, run the following commands.
        1. `git status` - This will give you a status of all the changes made.
        2. `git add .` - This will stage all your changes to be committed.
        3. `git commit -m "<your commit message>"` - This will commit the changes locally. Make sure the commit message is something meaningful like "Adding solution to task X for week Y of <seminar/practicum>".
    - **Each task should be in separate commit.**
    - [About commits.](https://docs.github.com/en/desktop/contributing-and-collaborating-using-github-desktop/making-changes-in-a-branch/committing-and-reviewing-changes-to-your-project#about-commits)
    - Repeat step 6. and 7. until you have all your tasks for the given week in the new branch.

8. Push your changes to the remote repository
    - After you have committed locally all the solutions run the following command to upload them to **your** remote repository:
        - `git push` - This will sync your local changes to the remote repository e.g. upload all your files to the remote.

9. Open PR to the original repository to the master branch
    - [How to create pull request.](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request)
    - The pull request should request to merge the changes of your branch in the fork to the master branch of the original repository.
    - **The title of the Pull Request should be:**
        ```
        <Practicum\Seminar>.\<number\>: Add \<first task number\> - \<last task number\> | \<name\>
        
        Example:
        Practicum.03: Add 01-03 | John Doe
        ```
    - **The description of the pull Request should be**
        ```
        \<name\> \<last name\>
        \<major\> \<group\> \<fn\>

        Example:
        John Doe 
        SI 2 2MI0600192
        ```


| :boom: **WARNING**|
|:-----------------|
| ***If the title or description of the pull request are not exactly like the format described above, the PR will be rejected and will not be reviewed.***|