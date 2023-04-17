# jif.mcfunction
# __arg1 condition value
# __arg2 __pc value
# returns nothing
#
# change __pc to the given value, if condition is NOT zero.
execute unless score __arg1 Internal matches 0 run scoreboard players operation __pc Internal = __arg2 Internal