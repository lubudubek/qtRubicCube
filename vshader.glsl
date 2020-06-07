#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

uniform mat4 mvp_matrix;
//uniform mat4[24] cubic_matrix;

attribute vec4 a_position;
attribute vec2 a_texcoord;
attribute float a_cubicNumber;


varying vec2 v_texcoord;

//! [0]
void main()
{
    // Calculate vertex position in screen space
    if(a_cubicNumber < 4.0)
    {
        gl_Position = mvp_matrix * a_position;
        v_texcoord = a_texcoord;
    }
    else
    {
        gl_Position = vec4(0,0,0,0);
        v_texcoord = vec2(0,0);
    }
    // Pass texture coordinate to fragment shader
    // Value will be automatically interpolated to fragments inside polygon faces

}
//! [0]
