# **Battle Angel -- Elma**

Final project for ECE 590

--
### Background and Introduction

**Elma** is a battle angel and she need to cross a forest. However, the forest in this game is very different. Some positions in the forest have poison that can damage our Battle Angle, which means the vitality of our Battle Angle will decrease by the value of the toxicity. 

Fortunately, there are some positions in the forest have potion for our Battle Angel! If the angel can arrive to these position before her vitality(life value) below than ``0``, she will be safe in this game. 

Thus, my final project is going to show the path for Battle Angel to across the dangerous forest.

**Details for my project**

Here are some connections between my final project and elma.

``Robot`` = ``elma`` = ``Battle Angel``

``2D environment`` = ``dangerous forest`` = ``maze``

``intruder`` = ``position with poison`` = ``number with negative value in the map``

``recharge station`` = ``position with potion`` = ``position with positive value`` = ``$$$``

--

### Goals for this project

Based on the ``elma`` manager and some scratch in C++, I am going to generate a path for my Battle Angel to go across the randomly generated dangerous forest safely and display the path in the terminal.

--

### Milestones for this project
1. **【Done】(Before 13rd Mar)** Develop the function for generating a random forest with "poisoned position" and "healing position"
2. **【Done】(Before 15th Mar)** Design and develop the method to visualize the forest and the path 
3. **(Before 19th Mar)** Try to find the connection between the ``forest``(which can be seen as a map) and the ``elma`` repo;
4. **(Before 20th Mar)** Write test case for my project, test my project
5. **(Before 21st Mar)** Finish the document for my project and improve the readability of my program 
6. **Extra:** Design a program to generate the best path for battle angle(eg. reach the end point with high life value)

--

### Current results 
I've designed the maze inorder to represent the dangerous forest. I've also wrote the main function and tested the game.

#### **Maze initialization**
``*S*`` represents ``start_point``, also refers to the position for Battle Angel. 

``*E*`` represents ``end_point``

``*$$$*`` represents ``charger_station`` with positive number(+10)

Number in this maze means poison with different lethality.

Using ``a``, ``s``, ``d``, ``w`` to control the battle angel.

![](/Users/corina/Desktop/EE_590/MyRepo/FinalProject/BattleAngel/img/UI1.png)
![alt text](https://github.com/yuew03/BattleAngel/blob/master/img/UI1.png)
#### **Game Process**
After reaching the charger,  the value of current life can be added by ten. Battle angel will have enough life value to the end point.
![](/Users/corina/Desktop/EE_590/MyRepo/FinalProject/BattleAngel/img/UI2.png)
![](/Users/corina/Desktop/EE_590/MyRepo/FinalProject/BattleAngel/img/UI3.png)
![](/Users/corina/Desktop/EE_590/MyRepo/FinalProject/BattleAngel/img/UI4.png)
![alt text](https://github.com/yuew03/BattleAngel/blob/master/img/UI2.png)
![alt text](https://github.com/yuew03/BattleAngel/blob/master/img/UI3.png)
![alt text](https://github.com/yuew03/BattleAngel/blob/master/img/UI4.png)



