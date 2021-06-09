#version 120
uniform sampler2D currentTexture;
uniform float time;

void main() {
    vec2 coord = gl_TexCoord[0].xy;  
    vec4 pixel_color = texture2D(currentTexture, coord);
    float alpha=0.5+0.5*cos(20*time);
if(gl_TexCoord[0].x > 100.0)
		gl_FragColor = vec4(pixel_color.xyz,min(alpha,pixel_color.w));
    else
   		gl_FragColor = vec4(pixel_color.xyz,min(alpha,pixel_color.w));
    //gl_FragColor = vec4 (pixel_color.xyz,min(alpha,pixel_color.w));
}
