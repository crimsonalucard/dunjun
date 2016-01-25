making a C++ game.

Framebuffers hold:
Color buffer (Colors RGB)
Depth (Grey scale the darker the farther)
Stencil (acts as a stencil look it up later)

GRAPHICS PIPELINE

VERTICES -> VERTEX SHADER -EXTRA-> GEOMETRY SHADER (ADDS EXTRA GEOMETRY, skippable)
->RASTERIZATION (TURNS INTO PIXELS) -> FRAGMENT SHADER (GETS PIXELS AND COLORS IT IN)
