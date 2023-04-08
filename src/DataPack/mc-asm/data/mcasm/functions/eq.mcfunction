# eq.mcfunction
# __arg1 integer A
# __arg2 integer B
# returns A == B
scoreboard players set __ret Internal 0
execute if score __arg1 Internal = __arg2 Internal run scoreboard players set __ret Internal 1
