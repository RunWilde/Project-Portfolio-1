
# Project & Portfolio 1

**Noah West**

Hello my name is Noah West. I am a student from franklin, Tennessee. The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

## Week 1
⚙️ Overview - What I worked on this past week

I worked on setting up a basic main menu as well as a combat menu. Right now I have a super basic combat scenario where it only really just drains the enemies health until they die, once that happens it returns you to the main menu. Besides that I set up basic stuff for the player with health and some other values as well as enemies.

🌵 Challenges - What problems did I have & how I'm addressing them

Time management was a big issue this week as I kept getting to focused on the overall project instead of breaking it down into multiple pieces, past that I also didn't start till later in the week. Didn't help I got sick part way through, so while I was overthinking how I was going to do things, I then was unable to think to begin with.

🏆 Accomplishments - What is something I "leveled up" on this week
I got through and really planned out how I want my game to look at a basic level and now I know what I want the flow to look like for the player. Intro and Menu -> New Game -> Character Creation -> Exploration with Random events including combat -> Find a way to escape the planet -> Victory.

🔮 Next Steps - What I plan to prioritize and do next
For week 2 I'm gonna hammer out the rest of the action point system for combat, build the character creator, an actual exploration mode with random events (basically the main game loop) and finally the weapon system.

## Week 2
⚙️ Overview - What I worked on this past week

The past week I've worked on UI updates and damage calculation for the players weapon.

🌵 Challenges - What problems did I have & how I'm addressing them

Time management was a big issue this week as I kept getting to focused on the overall project instead of breaking it down into multiple pieces, past that I also didn't start till later in the week. Didn't help I got sick part way through, so while I was overthinking how I was going to do things, I then was unable to think to begin with.

🏆 Accomplishments - What is something I "leveled up" on this week
My planning has gotten a lot better, I'm now even writing pseudocode that I can follow alongside my code that makes building much faster.

🔮 Next Steps - What I plan to prioritize and do next
I have essentially completed what I wanted to, or at least built out the foundations of what I need to build throughout week 3.
## Week 3
 ⚙️Overview – What did you work on this past week? I've been working through finishing my Gun Customization and fixing some UI issues. 
 
 🛠️ Improvements – What changes, refinements, or new features did you make? I've made an insane amount of setters and menu systems so . Starting with some of the first parts, I made setters that would go through and convert the current weapon mod to a new weapon mod. Then I made menus that would use these setters in a new select method so the user can swap the weapon mod with the various ones in the list. I also went and remade the main menu to let the user enter a menu to Customize a weapon, then test the weapon at a separate firing range. A lot of these features were done by utilizing what I was already creating for the RPG which I unfortunately will not be able to finish this month.
 
 🌵 Challenges – What obstacles did you encounter, and how are you addressing them? I'm still having small issues with the default constructor and small missing numerals that seem to be adding themselves onto the starting stats. The player weapon shouldn't have any stats outside of a default zero. The way I'm handling it trying to find these missing or hidden numerals is by using breakpoints to carefully look through each method and line of code. 
 
 💬 Feedback – What feedback have you received, and how will it influence your next steps? I've had a lot of useful feedback on each week, even in this chat too. A lot of the feedback is really just reinforcing the ideas and methods I was already going to do. An example is making the new training dummy have user inputted values for health and armor, that is something I was going to implement anyway as it's the best way to test the user made weapon. A great suggestion! 
 
 🔮 Next Steps – What is your primary goal for Week 4? The main goal for this week is just to refine the methods I've already created. Also I need to create my save and load functions so the user can save their creations and load presets whenever.
## Week 4
Project Progress: At this point most of the major systems for my project are finished or close to being finished. I have my weapon customization system working, including the different weapon parts, setters for swapping them, damage calculations, and the menus needed to actually customize a weapon. I also separated the firing range from the customization menu so the player can build a weapon and then go test it against a training dummy with custom health and armor values. Right now I'm mainly working on refining what I already have, fixing some remaining UI issues and minor loop bugs. I scrapped the Idea of the File/IO for the time being in favor of making sure the program runs well. 

Reflection: Looking back at my self-assessment from the beginning of the course, I think one of my biggest improvements has been planning and breaking a larger project into smaller systems. At the start of the course I was already fairly comfortable with things like classes, functions, and loops, but I had a bad habit of looking at the entire project at once and overthinking how everything should be structured. This project forced me to get better at separating features into individual tasks and figuring out which classes should actually be responsible for different parts of the program. This project also made me even more comfortable with a lot of the concepts I had already established a good understanding of. 

One Surprise: Something surprising I've accomplished is how modular the project became compared to what I originally started with. My UI system is probably my favorite example. I created a reusable menu handler with input validation, and once I had that working I was able to reuse it for a lot of the other menus instead of rewriting the same logic every time. I also didn't expect the weapon customization system to become as involved as it did, especially with all of the different setters, selector functions, and the overall calculations. 

One goal for the future: A skill I still want to work on after this course is planning my code before I start implementing it. I've definitely improved at breaking features into smaller tasks, but I still sometimes overthink the overall structure. I want to get better at recognizing those problems earlier so I don't get as stumped as I have in the past and even with this project Something I'm 

Exploring: Might be a bit simple here but I had to research the differences between building the project as a Debug vs Release version. I was looking into this because I was wanting to ship off my program even in it's current state to a couple of friends for them to review and try to break it. It wasn't too hard to research but it's great to know the differences between the two.
### Week 1
Finished setting up the basic UI layout for a main menu and a combat menu. I also have a very basic combat scenario where you only really attack an enemy until you drain their health and they die. But it does manage to loop out of the combat when the enemy is dead and returns the player to the main menu. Started working on an action point system which will be finished into week 2.
### Week 2
Went and worked on a bunch of UI updates and set up a basic damage calculation for the players weapon. That week was spent on a lot of UI functions like a universal menu handler which has made making menus really easy and already built in input validation. I also spent it converting menus that I had previously not using the menu handler over to use it instead of just displaying the menu by itself. Finally that week I also built the foundation for the weapon class and the damage calculation so I could get started on the weapon customization over week 3.
### Week 3
Spent most of this week finishing up the Gun Customization system and fixing some UI issues. I created a large number of setters and menus that let the player swap different weapon mods, and then rebuilt the main menu so weapon customization and the firing range are separated into their own sections. A lot of the systems I built were reused from ideas I had already planned for the RPG, even though I won’t be able to finish the full RPG this month. I also spent time debugging some strange starting stat values by using breakpoints to track down where those extra numbers are coming from.
### Week 4

At this point most of the major systems for my project are finished, including the weapon customization, damage calculations, and firing range. I spent time most of the time polishing the program, fixing UI issues and a few minor loop bugs, and I decided to scrap File I/O for now so I could focus on making sure everything runs well. Looking back, I think my biggest improvement has been learning how to break a larger project into smaller systems instead of overthinking everything at once. I was also surprised by how modular the project became, especially with the reusable UI menu handler and weapon customization system. Going forward I still want to improve how I plan my code before implementing it, and this week I also researched the difference between Debug and Release builds so I could send the program to a few friends for testing.
