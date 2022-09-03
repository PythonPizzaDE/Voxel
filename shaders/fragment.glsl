#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

void main()
{
    float d1 = distance(vec2(0.0, 0.0), TexCoord);
    float d2 = distance(vec2(1.0, 0.0), TexCoord);
    float d3 = distance(vec2(0.0, 1.0), TexCoord);
    float d4 = distance(vec2(1.0, 1.0), TexCoord);

    float rd1 = min(d1, d2);
    float rd2 = min(d3, d4);
    float dist = min(rd1, rd2);
    float fac = (1.0 - dist) / 2 + 0.5;
    FragColor = normalize(vec4(1.0 * fac, 0.1 * fac, 0.1 * fac, 1.0));
}
