# mod.mcfunction
# __arg1 integer A
# __arg2 integer B
# returns A % B
scoreboard players operation __ret Internal = __arg1 Internal
scoreboard players operation __ret Internal %= __arg2 Internal