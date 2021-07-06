print("""
<x=6, y=-2, z=-7>
<x=-6, y=-7, z=-4>
<x=-9, y=11, z=0>
<x=-3, y=-4, z=6>
""")
struct Planet 
    x
    y
    z
    vx
    vy
    vz
end
N=1000

function check(a,b) begin
    if a > b  
        +1
    elseif a < b
        -1
    else 
        0
    end
end

function 

function Agrav!(Planet::A, Planet::B) begin
        B.vx += -check(A.x,B.x)
        B.vy += -check(A.y,B.y)
        B.vz += -check(A.z,B.z)
        A.vx += check(A.x,B.x)
        A.vy += check(A.y,B.y)
        A.vz += check(A.z,B.z)      
end

function move!(Planet::C) begin
    C.x += C.vx
    C.y += C.vy
    C.z += C.vz
end

Planets = [Planet(6,-2,-7), Planet(-6,-7,-4), Planet(-3,-4,6)]
for i in range 1:1:N begin
    move!.(Planets)
    for (ind, PA) in enumerate(Planets) begin
        for (jnd, PB) in enumerate(Planets[ind:end]) begin
            Agrav!(PA,PB)
        end
    end
end