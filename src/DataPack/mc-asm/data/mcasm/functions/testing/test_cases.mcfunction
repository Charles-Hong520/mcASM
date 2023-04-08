# test_cases.mcfunction
# testing/test_function.mcfunction will be ran with the following arguments.
# this is meant to be only used while testing.

scoreboard players set __arg1 Internal 0
scoreboard players set __arg2 Internal 0
function mcasm:testing/test_function
function mcasm:testing/print_internals

scoreboard players set __arg1 Internal 10
scoreboard players set __arg2 Internal 0
function mcasm:testing/test_function
function mcasm:testing/print_internals

scoreboard players set __arg1 Internal 0
scoreboard players set __arg2 Internal 10
function mcasm:testing/test_function
function mcasm:testing/print_internals

scoreboard players set __arg1 Internal 10
scoreboard players set __arg2 Internal 20
function mcasm:testing/test_function
function mcasm:testing/print_internals

scoreboard players set __arg1 Internal 10
scoreboard players set __arg2 Internal -20
function mcasm:testing/test_function
function mcasm:testing/print_internals

scoreboard players set __arg1 Internal -100
scoreboard players set __arg2 Internal -10
function mcasm:testing/test_function
function mcasm:testing/print_internals

scoreboard players set __arg1 Internal -10
scoreboard players set __arg2 Internal -10
function mcasm:testing/test_function
function mcasm:testing/print_internals

scoreboard players set __arg1 Internal 30
scoreboard players set __arg2 Internal 30
function mcasm:testing/test_function
function mcasm:testing/print_internals