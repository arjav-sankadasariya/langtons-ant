
<a name="readme-top"></a>
<!--
*** Thanks for checking out this Ants Simulation project. If you have any suggestions
*** or find any issues, please feel free to open an issue or contribute to the project.
*** Don't forget to give the project a star!
*** Now go simulate some ants and have fun! 🐜🎉
-->

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <h3 align="center">Ants Simulation</h3>
  
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li><a href="#how-to-run">How to Run</a></li>
    <li><a href="#screenshots">Screenshots</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project

Langton's Ant is a cellular automaton model consisting of an ant moving on a grid according to some simple rules, creating interesting patterns over time. The emergent behavior of this model demonstrates how complex patterns can emerge from simple rules.  Have fun exploring the world of ants!

### Built With
![c_logo](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

<!-- HOW TO RUN -->
## How to Run

1. Compile the project using a C compiler (e.g., GCC).
   ```sh
   gcc main.c newSleep.c random.c color.c -o ant
2. Use Command-Line Arguments to play the Ant Simulation
   ```sh
   ./ant test.txt niterations tsleep
   ```
   For example
   ```sh
   ./ant map.txt 100 0.5
## Screenshots
![Screenshot 1](/images/map1.png)
<br>
![Screenshot 2](/images/map2.png)
