uniform sampler2D samInput0;
uniform sampler2D samInput1;
uniform sampler2D samInput2;
uniform sampler2D samInput3;
uniform sampler2D samInput4;
uniform sampler2D samInput5;
uniform sampler2D samInput6;
uniform sampler2D samInput7;

//uniform mat4 uHSCB;

vec3 saturate(vec3 v)
{
	return clamp(v, vec3(0), vec3(1));
}

vec3 AdjustColor(vec3 color)
{
	color = saturate(color-vec3(64/255.0));
	color = saturate(color*vec3(16*40.0/255.0));
	color = mix(vec3(255.0/255.0, 255.0/255.0, 255.0/255.0), vec3(208.0/255.0, 220.0/255.0, 224.0/255.0), color);
	
	return color;
}

vec3 AdjustCB(vec3 color, float contrast, float brightness)
{
	color = (color-vec3(0.5))*contrast+vec3(0.5);
	color = color*vec3(brightness);
	return color;
}

vec3 Subroutine0(vec3 color1, vec3 color2)
{
	color1 = AdjustColor(color1);
	color2 = AdjustColor(color2);
	
	return saturate(AdjustCB((color1-(color2*0.5+0.4)), 0.75, 0.78));
}

void main(void)
{
	vec3 color = 0.5*texture2D(samInput1, gl_TexCoord[0].st).xyz;

	color += Subroutine0(
			texture2D(samInput2, gl_TexCoord[0].st).xyz,
			texture2D(samInput3, gl_TexCoord[0].st).xyz
		);

	color += 0.15*Subroutine0(
			texture2D(samInput4, gl_TexCoord[0].st).xyz,
			texture2D(samInput5, gl_TexCoord[0].st).xyz
		);
	
	//color *=10;
	//color+0.3;
	//color = mix(vec3(20.0/255.0, 22.0/255.0, 21.0/255.0), vec3(86.0/255.0, 88.0/255.0, 87.0/255.0), saturate(color));
	
	float ca = cos(-0.63), sa = sin(-0.63);
	float x = ca*gl_TexCoord[0].s - sa*gl_TexCoord[0].t;
	float y = sa*gl_TexCoord[0].s + ca*gl_TexCoord[0].t;

	//x = x*0.312+0.5;
	//y = y*0.312+0.5;
	
	vec3 color1 = texture2D(samInput7, vec2(x, y)).xyz;
	color1 = vec3(1.0)-AdjustCB(color1, 2.726, 6.904);
	
	color1 = mix(vec3(0.0/255.0, 0.0/255.0, 0.0/255.0), vec3(209.0/255.0, 224.0/255.0, 96.0/255.0), color1);
	color1 = AdjustCB(color1, 1.128, 0.380);
	
	vec3 color2 = texture2D(samInput6, gl_TexCoord[0].st).xyz;
	color2 = mix(vec3(48.0/255.0, 0.0/255.0, 11.0/255.0), vec3(134.0/255.0, 55.0/255.0, 32.0/255.0), color2);
	color2 = AdjustCB(color2, 1.272, 0.872);
	color2 = saturate(color2)+saturate(color1);
	
	vec3 colorM = texture2D(samInput0, gl_TexCoord[0].st).xyz;
	colorM = saturate(AdjustCB(colorM, 20.52, 0.14));

	gl_FragColor = vec4(mix(color, color2, colorM), 1);
}