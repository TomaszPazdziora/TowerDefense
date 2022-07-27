# Tower Defense – consol game
The game starts in the main menu where the player can choose one option. The project is in progress and has not had some functionality yet. Currently, it is possible to watch the presentation of 3 different maps. The demonstration presents one wave of attackers who move across the map to the player base. If the player wants to test the application now, he/she should choose the option "Present Map" and then pick the map.

## Presentation mode

```
       %%%%%%%%%%%%%%%
       %   9         B
       % %%%%%%%%%%%%%
       % 2    8   %
       %%%%%%%%%% %
                %7%
%%%%%%%%%%%%%%%%% %
E       1  3  4   % 
%%%%%%%%%%%%%%%%%%%
```

The picture shows an example of presentation mode. Numbers symbolize attackers and their value which tells how strong the attacker is. Attackers spawn in the B point and move across the map to the E point. Aggressors move for blanc cells (space bars). % symbolize defender walls (it will be possible to set defenders in those locations in the future). Map and menu store in txt files. Every map or menu has its directory. The appearance of the menu and maps are obtained by the program's logic.

## Creating maps 

Txt map files are written in strictly defined rules. Spawn points are connected with the player base by a path. Every map starts by: ‘,’ or ‘6’ or ‘v’ or ‘.’ character. The first path character depends on the direction in which the path will go. 

- , -  the path starts in the left direction 
-	6 -  the path starts up 
-	v -  path starts down 
- . - the path starts in the right direction 

It is necessary to connect the beginning of the path with the ‘E’ character. In the middle of the map, navigation is described by: 
-	< -  path goes left 
-	^ -  the path goes up 
-	V - path goes down 
-	\> -  the path goes right

```
       %%%%%%%%%%%%%%%
       %V<<<<<<<<<<<<,
       %V%%%%%%%%%%%%%
       %>>>>>>>>>V%
       %%%%%%%%%%V%
                %V%
%%%%%%%%%%%%%%%%%V%
E<<<<<<<<<<<<<<<<<%
%%%%%%%%%%%%%%%%%%%
```
The picture shows correct .txt map file of higher presented map.

