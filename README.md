# 📳 Minitalk

##### _Summary: The purpose of this project is to code a small data exchange program using UNIX signals._


##### _Version: 2_

_버전 2_

<br>

# Contents

| Chapter |                     Contents                     | page |
| :-----: | :----------------------------------------------: | :--: |
|    I    |            [**Foreword**](#chapter-1)            |  2   |
|   II    |      [**Common Instructions**](#chapter-2)       |  3   |
|   III   |     [**Project Instructions**](#chapter-3)       |  5   |
|   IV    |         [**Mandatory part**](#chapter-3)         |  6   |
|    V    |           [**Bonus part**](#chapter-4)           |  7   |
|   VI    | [**Submission and peer-evaluation**](#chapter-5) |  8   |

<br>

# Chapter 1

## Foreword

##### _The cis-3-Hexen-1-ol, also known as (Z)-3-hexen-1-ol and leaf alcohol, is a colorless oily liquid with an intense grassy-green odor of freshly cut green grass and leaves._


##### _It is produced in small amounts by most plants and it acts as an attractant to many predatory insects. cis-3-Hexen-1-ol is a very important aroma compound that is used in fruit and vegetable flavors and in perfumes._


##### _The yearly production is about 30 tonnes._


<br>

# Chapter 2

## Common Instructions

- ##### _Your project must be written in C._


- ##### _Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside._


- ##### _Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation._


- ##### _All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated._


- ##### _If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, and your Makefile must not relink._


- ##### _Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re._


- ##### _To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file \_bonus.{c/h}. Mandatory and bonus part evaluation is done separately._


- ##### _If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project._


- ##### _We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating._


- ##### _Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop._

<br>

# Chapter 3

## Project instructions

- ##### _Name your executable files `client` and `server`._


- ##### _You have to turn in a `Makefile` which will compile your source files. It must not relink._


- ##### _You can definitely use your `libft`._


- ##### _You have to handle errors thoroughly. In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth)._


- ##### _Your program mustn't have `memory leaks`._


- ##### _You can have `one global variable per program` (one of the client and one for the server), but you will have to justify their use._


- ##### _In order to complete the mandatory part, you are allowed to use the following functions:_


  - `write`
  - `ft_printf`
  - `signal`
  - `sigemptyset`
  - `sigaddset`
  - `sigaction`
  - `kill`
  - `getpid`
  - `malloc`
  - `free`
  - `pause`
  - `sleep`
  - `usleep`
  - `exit`


<br>

# Chapter 4

## Mandatory Part

##### _You must create a communication program in the form of a `client` and a `server`._


- ##### _The server must be launched first. After its launch, it has to print its PID._


- ##### _The client take two parameters:_


	- ##### _The server PID._


	- ##### _The string to send._


- ##### _The client must communicate the string passed as a parameter to the server. Once the string has been received, the server must print it._


- ##### _The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long._


> 💡 <br>
>
> ##### _1 secon for displaying 100 character is way too much!_
>
>

- ##### _Your server should be able to receive strings from several clients in a row without needing to restart._

  
- ##### _The communication between your client and your server has to be done only using programs should ONLY using UNIX signals._


- ##### _You can only use the two signals `SIGUSR1` and `SIGUSR2`._


> ⚠️ <br>
>
> ##### _Linux system does NOT queue signals when you already have pending signal of this type! Bonus time?_
>

<br>

# Chapter 5

## Bonus part

##### _Bonus list :_

- ##### _The server acknowledge every message received by sending back a signal to the client._

	
- ##### _Unicode characters support!_


> ⚠️ <br>
>
> ##### _The boonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without amlfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all._
>
>

<br>

# Chapter 6

## Submission and peer-evaluation

##### _Turn in your assignment in your `Git` repository as usual. Only the work inside your repository will be evaluated during the defense. Don't hesitate to double check the names of your files to ensure they are correct._
 
