#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

uniform mat4 mvp_matrix;
uniform mat4 CubicTransformMatrix_0;
//uniform mat4[24] cubic_matrix;

attribute vec4 a_position;
attribute vec4 a_color;
attribute float a_cubicNumber;


varying vec4 v_color;

//! [0]
void main()
{
    // Calculate vertex position in screen space
//    if(a_cubicNumber < 2.5)
//    {
        gl_Position = mvp_matrix * CubicTransformMatrix_0 * a_position;
        v_color = a_color;
//    }
//    else
//    {
//        gl_Position = mvp_matrix * CubicTransformMatrix_0 * a_position;
//        v_color = vec4(0.0 ,0.0 ,1.0 ,0.2);
//    }
    // Pass texture coordinate to fragment shader
    // Value will be automatically interpolated to fragments inside polygon faces

}
//! [0]
