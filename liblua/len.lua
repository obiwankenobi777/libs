#!/usr/bin/lua

function main()
    if #arg == 0 then
        print("Missing Arguments")
        return 1
    end

    local chars, words = 0, 0
    for i = 1, #arg do
        io.write("["..i.."] " .. arg[i].." -> " .. #arg[i] .. "\n")
        chars = chars + #arg[i]
        words = words + 1
    end
    io.write("\nWords -> " .. words)
    io.write("\nCharacters -> " .. chars .. "\n")
end

main()
