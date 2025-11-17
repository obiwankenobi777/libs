local Set = {}
local mt = {}

-- Verifica se algo é um conjunto válido
local function isSet(s)
    return type(s) == "table" and getmetatable(s) == mt
end

function Set.new(l)
    local set = {}
    setmetatable(set, mt)
    for _, v in ipairs(l) do
        set[v] = true
    end
    return set
end

-- União
function Set.union(a, b)
    if not isSet(a) or not isSet(b) then
        error("Attempt to 'add' a set with a non-set value", 2)
    end

    local res = Set.new{}
    for k in pairs(a) do res[k] = true end
    for k in pairs(b) do res[k] = true end
    return res
end

-- Interseção
function Set.intersection(a, b)
    if not isSet(a) or not isSet(b) then
        error("Attempt to 'mul' a set with a non-set value", 2)
    end

    local res = Set.new{}
    for k in pairs(a) do
        if b[k] then
            res[k] = true
        end
    end
    return res
end

-- tostring
function Set.tostring(set)
    local l = {}
    for i in pairs(set) do
        table.insert(l, i)
    end
    return "{" .. table.concat(l, ", ") .. "}"
end

function Set.print(s)
    print(Set.tostring(s))
end

-- Define metamétodos
mt.__add = Set.union
mt.__mul = Set.intersection
mt.__tostring = Set.tostring

-- Subconjunto (<=)
mt.__le = function(a, b)
    for i in pairs(a) do
        if not b[i] then
            return false
        end
    end
    return true
end

-- Subconjunto próprio (<)
mt.__lt = function(a, b)
    return a <= b and not (b <= a)
end

-- Igualdade de conjuntos
mt.__eq = function(a, b)
    return a <= b and b <= a
end

-- ---------------------------
-- TESTES
-- ---------------------------

s1 = Set.new{10, 20, 30, 50}
s2 = Set.new{30, 1}
s3 = s1 + s2

Set.print(s1)
Set.print(s2)
Set.print(s3)

Set.print((s1 + s2) * s3)
Set.print(s1 * s2)

s1 = Set.new{2, 4}
s2 = Set.new{4, 10, 2}

print(s1 <= s2)
print(s1 < s2)
print(s1 >= s1)
print(s1 > s1)

