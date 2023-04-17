tellraw @a {"text": "MC-ASM Loaded!", "color": "blue"}

scoreboard objectives add Internal dummy
scoreboard objectives add Variables dummy

scoreboard players reset * Internal
scoreboard players reset * Variables

scoreboard objectives setdisplay sidebar Internal

scoreboard players add __arg1 Internal 0
scoreboard players add __arg2 Internal 0
scoreboard players add __arg3 Internal 0
scoreboard players add __ret Internal 0
scoreboard players add __pc Internal 1
