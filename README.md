  <a name="readme-top"></a>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/conu101/fillit">
    <img src="images/noun-puzzle-5278809.png" alt="Logo" width="200" height="200">
  </a>

  <h3 align="center">Fillit </h3>
  <h3 align="center">(to sing on MJ's "Beat it" tune)</h3>

  <p align="center">
    <br /> Video clip: https://www.youtube.com/watch?v=oRdxUFDoQe0
    <br />
    <br />
    <br /> 42 Helsinki third school project: coding a little variant of Tetris game.
	Group project done with Tuomas Burakowski.
  </p>
    <br />
    <br />
    <br />
    <br />
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

  <a href="https://github.com/conu101/fillit">
    <img src="images/noun-c-file-896983.png" alt="Logo" width="80" height="80">
  </a>

The goal of this project is to code a variant of the famous game Tetris: a list of tetriminos (4 blocks arranged in various shapes similarly to those found in Tetris) is provided in a text file, as successive shapes drawn with '#' and '.'.
The goal is to find the smallest possible square within which all blocks can be placed, with each block at their most top-left possible position. There can be between 1 and 26 tetriminos, separated by a newline in the text file.

The result must be displayed in the standard output, with the first tetrimino represented by the letter A, the second by B, and so on.

If a faulty file is entered as an argument, the program displays "error" and quits. If no file or more than 1 file is entered as argument, the program
displays the usage and quits.

Example: text file including 3 tetriminos <trial.txt>
```sh
...#
...#
...#
...#

....
#...
#...
##..

...#
...#
..##
....
```

Command:

./fillit trial.txt

Result on stdout:
```sh
AB..
AB.C
ABBC
A.CC
```
The main steps to succeed in the fillit project were:

interpersonal: 
* getting a clear roadmap of the work to be done and dividing it within our team
* writing clear pseudocode
* managing the branch merging on github

technical:
* reading the parameter files, managing error input to avoid segmentation fault
* parsing the input into matrixes
* optimizing the calculation speed through recursive functions.

This project was very satisfying to code even if we pulled our hair a few times with my work partner.


### Built With

* [![C][C.js]][C-url]
* [![VS-Code][VS-Code.js]][VSCode-url]



<!-- GETTING STARTED -->
## Getting Started

The project can be set up locally by downloading or cloning the repository. It has been built on and for macos so its functionality is not guaranteed on other operating systems.

The project required the use of the static library libft.a coded during the previous project. The libft version used in this projct is the version I had put together in that time, much more limited than the currently available version that has been updated since.
See libft project -> [https://github.com/conu101/libft](https://github.com/conu101/libft)

The executable "fillit" is available in this repo for direct use, but the project can also be recompiled following the steps presented next. If you use the available executable from this repo, ignore steps 4 and 5.

### Installation

1. Open a terminal on your machine

2. Clone the repo
   ```sh
   git clone https://github.com/conu101/Get_next_line.git <your_local_repository>
   ```
3. Get in your new repository
   ```sh
   cd <your_local_repository>
   ```
4. Compile the project using the Makefile
   ```sh
   make
   ```
5. Check that the executable <fillit> was created and delete the object files
   ```sh
   make clean
   ```
6. Run the executabe with a text file as argument (for example on of the testfiles included)
	```sh
	./fillit testfiles/trial26.txt
	```
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage


	ctrouve@Constances-MBP fillit_git % ./fillit testfiles/trial26.txt


	AAB.C.DEEF.
	AAB.CDDEEFF
	GGBBCDHHI.F
	GGJ.CHHOIKK
	NJJLLLLOIKK
	NJMM.P.OIQQ
	NNMMPPROTQQ
	SSU.PVRRT..
	SSUYVV.RTT.
	WWUYVXXXXZZ
	WWUYY...ZZ.

	./fillit testfiles/trial26.txt  0.00s user 0.00s system 45% cpu 0.005 total


In this case the maximum number of dominos (26) are arranged according to the rules. The calculation lasted under 0.01 s.

All files added in the testfile folder can be tried, and new combinations can be imagined as well, have fun!

<!-- CONTRIBUTING -->
## Contributing

The collaboration with my co-student Tuomas Burakowski was **greatly appreciated**. We worked on this project for 1 month and got a grade of 94%.


<!-- CONTACT -->
## Contact

Constance Trouvé - firstname.name(at)gmail.com

Project Link: [https://github.com/conu101/Get_next_line](https://github.com/conu101/Get_next_line)




<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

Illustrations obtained from "The Noun Project", credits:
* "Puzzle" by Liberus from <a href="https://thenounproject.com/browse/icons/term/puzzle/" target="_blank" title="Puzzle Icons">Noun Project</a>
* "C File" by Hea Poh Lin from <a href="https://thenounproject.com/browse/icons/term/c-file/" target="_blank" title="C File Icons">Noun Project</a>

"C" and "VSCode" badges from <a href="https://img.shields.io" target="_blank" title="badges">img.shields.io</a>

README template by Othneil DREW from <a href=https://github.com/othneildrew/Best-README-Template target="_blank" title="git">Git_README_template</a>

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/othneildrew/Best-README-Template/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge
[stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/othneildrew/Best-README-Template/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
[product-screenshot]: images/screenshot.png
[C.js]: https://img.shields.io/badge/C--programming-C-blue
[C-url]: https://www.w3schools.com/c/c_intro.php
[VS-Code.js]: https://img.shields.io/badge/Visual%20Studio%20Code-VSC-blue
[VSCode-url]: https://code.visualstudio.com/
