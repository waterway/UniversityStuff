#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rx = 0.0f;
float move_right_left = 0.0f, move_forward_back = 2.0f;	
float speed_right_left = 0.0f, speed_forward_back = -5.0f;
float angle = 0.0f;

float moveLight_Left_right = 0.0f, moveLight_forward_back = -10.0f;
float speedLightLR = 0.0f, speedLightFB = 0.0f;

/****************************************************************************************/
/*
    funksioni per ndertimin e ground of classroom
*/
static void classroomGround( double x, double y, double z )
{
    glPushMatrix( );
        glTranslatef( x, y, z );
        glColor3f( 0.8f, 0.8f, 0.8f );
        glScalef( 65.0f, 1.0f, 48.0f );
        glutSolidCube( 1.0f );
    glPopMatrix( );
}

/****************************************************************************************/
/*
    funksioni per ndertimin e derases
*/
static void derasa( double pozX, double pozY, double pozZ )
{
    glPushMatrix( );
        glTranslatef( pozX, pozY, pozZ );
        glColor3f( 0.0f, 0.0f, 0.0f );
        glScalef( 1.0f, 8.0f, 20.0f );
        glutSolidCube( 1.0f );
    glPopMatrix( );   
}


/****************************************************************************************/
/*
    funksioni per ndertimin e tavolinave
*/
static void tavolinat( double pozX, double pozY, double pozZ )
{
    glPushMatrix( );   
        glTranslatef( pozX, pozY, pozZ );
        glColor3f( 0.8f, 0.6f, 0.5f );
        
        // top
        glPushMatrix( );
            glTranslatef( 0.0f, 0.0f, 0.0f );
            glScalef( 5.0f, 0.5f, 10.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        // kembet
        glPushMatrix( );
            glTranslatef( 2.2f, -1.5f, 4.0f );
            glScalef( 0.5f, 3.0f, 0.5f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        glPushMatrix( );
            glTranslatef( -2.2f, -1.5f, 4.0f );
            glScalef( 0.5f, 3.0f, 0.5f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        glPushMatrix( );
            glTranslatef( 2.2f, -1.5f, -4.0f );
            glScalef( 0.5f, 3.0f, 0.5f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        glPushMatrix( );
            glTranslatef( -2.2f, -1.5f, -4.0f );
            glScalef( 0.5f, 3.0f, 0.5f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        
    glPopMatrix( );
}

/****************************************************************************************/
/*
    funksioni per ndertimin e klasave
*/
static void klasat( double pozX, double pozY, double pozZ, double angle )
{
    glPushMatrix( );
        glTranslatef( pozX, pozY, pozZ );
        glRotatef( angle, 0.0f, 1.0f, 0.0f );
        glColor3f( 0.8f, 0.5f, 0.2f );
        
        // muri 1
        float i, j;
        for ( i = -30.0f; i <= 30.0f; i += 20.0f )
        {
            glPushMatrix( );
                glTranslatef( i, 10.0f, 0.0f );
                glScalef( 3.5f, 20.0f, 1.0f );
                glutSolidCube( 1.0f );
            glPopMatrix( );   
        }
        glPushMatrix( );
            glTranslatef( 0.0f, 2.5f, 0.0f );
            glScalef( 60.0f, 5.0f, 1.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        glPushMatrix( );
            glTranslatef( 0.0f, 17.5f, 0.0f );
            glScalef( 60.0f, 5.0f, 1.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        // ||
        glPushMatrix( );
            glTranslatef( 0.0f, 10.0f, 0.0f );
            glScalef( 17.0f, 0.25f, 1.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        glPushMatrix( );
            glTranslatef( 20.0f, 10.0f, 0.0f );
            glScalef( 17.0f, 0.25f, 1.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        glPushMatrix( );
            glTranslatef( -20.0f, 10.0f, 0.0f );
            glScalef( 17.0f, 0.25f, 1.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        for ( j = -30.f; j <= 30.0f; j += 5.0f )
        {
            glPushMatrix( );
                glTranslatef( j, 10.0f, 0.0f );
                glScalef( 0.25f, 10.0f, 1.0f );
                glutSolidCube( 1.0f );
            glPopMatrix( );
        }
        
        // muri 2 dhe 3
        glPushMatrix( );
            glTranslatef( -32.0f, 10.0f, 22.5f );
            glScalef( 1.0f, 20.f, 45.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        glPushMatrix( );
            glTranslatef( 32.0f, 10.0f, 22.5f );
            glScalef( 1.0f, 20.f, 45.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        
        // muri 4
        glPushMatrix( );
            glTranslatef( -10.0f, 10.0f, 45.0f );
            glScalef( 45.0f, 20.0f, 1.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        glPushMatrix( );
            glTranslatef( 27.5f, 10.0f, 45.0f );
            glScalef( 10.0f, 20.0f, 1.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        glPushMatrix( );
            glTranslatef( 20.0f, 17.5f, 45.0f );
            glScalef( 20.f, 5.0f, 1.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        
        GLfloat a, b;
        for ( a = -20.0f; a <= 10.0f; a += 15.0f )
        {
            for ( b = 10.0f; b <= 45.0f; b += 15.0f )   
            {
                tavolinat( a, 3.0f, b );
            }
        }
        
        derasa( 31.0f, 8.0f, 25.0f );
        classroomGround( 0.0f, 0.0f, 24.0f );
        classroomGround( 0.0f, 20.0f, 24.0f );
        
    glPopMatrix( );   
}

/****************************************************************************************/
/*
    funksioni per ndertimin e librarise
*/
static void libraria( double x, double y, double z )
{
    glPushMatrix( );
        glTranslatef( x, y, z );
        glColor3f( 0.8f, 0.5f, 0.2f );
        
        // muri pas
        float i;
        for ( i = -60.0f; i <= 60.0f; i += 20.0f ) 
        { 
            glPushMatrix( ); 
                glTranslatef( i, 10.0f, 0.0f );
                glScalef( 10.0f, 20.0f, 0.5f );
                glutSolidCube( 1.0f );
            glPopMatrix( ); 
        }
        
        glPushMatrix( );
            glTranslatef( 0.0f, 2.5f, 0.0f );
            glScalef( 120.0f, 5.0f, 0.5f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        glPushMatrix( );
            glTranslatef( 0.0f, 18.5f, 0.0f );
            glScalef( 120.0f, 5.0f, 0.5f );
            glutSolidCube( 1.0f );
        glPopMatrix( );

        // muri para
        float j;
        for ( j = -60.0f; j <= 40.0f; j += 20.0f ) 
        { 
            glPushMatrix( ); 
                glTranslatef( j, 10.0f, 110.0f );
                glScalef( 10.0f, 20.0f, 0.5f );
                glutSolidCube( 1.0f );
            glPopMatrix( ); 
        }
        
        glPushMatrix( );
            glTranslatef( -10.0f, 2.5f, 110.0f );
            glScalef( 110.0f, 5.0f, 0.5f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        glPushMatrix( );
            glTranslatef( -10.0f, 18.5f, 110.0f );
            glScalef( 110.0f, 5.0f, 0.5f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        
        // muri krah
        glPushMatrix( );
            glTranslatef( -65.0f, 10.0f, 55.0f );
            glScalef( 0.5f, 20.0f, 110.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        
        // muri krah
        glPushMatrix( );
            glTranslatef( 65.0f, 10.0f, 25.0f );
            glScalef( 0.5f, 20.0f, 50.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        
        // tavolinat
        tavolinat( 0.0f, 0.0f, 0.0f );
        
    glPopMatrix( );   
}

/****************************************************************************************/
/*
    funksioni per ndertimin e skaleve
*/
static void shkallet1( double x, double y, double z )
{
    glPushMatrix( );
        glTranslatef( x, y, z );
        glColor3f( 0.8f, 0.8f, 0.8f );
        
        float z2 = 0.0f, z3 = 0.0f;
        float i, j, i2, j2;
        for ( i = 0.0f, j = 60.0f; i <= 5.0f, j >= 5.0f; i += 1.0f, j -= 6.0f )
        {
                glPushMatrix( );
                    glTranslatef( 0.0f, i, z2 );
                    glScalef( 25.0f, 1.0f, j );
                    glutSolidCube( 1.0f );
                glPopMatrix( );
                z2 -= 3.0f;
        }
        
        glPushMatrix( );
            glRotatef( 180.0f, 0.0f, 1.0f, 0.0f );
            for ( i2 = 10.0f, j2 = 60.0f; i2 <= 20.0f, j2 >= 5.0f; i2 += 1.0f, j2 -= 6.0f )
            {
                    glPushMatrix( );
                        glTranslatef( -20.0f, i2, z3 );
                        glScalef( 25.0f, 1.0f, j2 );
                        glutSolidCube( 1.0f );
                    glPopMatrix( );
                    z3 -= 3.0f;
            }
        glPopMatrix( );
        
        glPushMatrix( );
            glTranslatef( 10.0f, 10.0f, -30.0f );
            glScalef( 45.0f, 1.0f, 15.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        
       glPopMatrix( );
}

/****************************************************************************************/
/*
    funksioni per ground of levels
*/
static void miniGroundsGodinaA( double x, double y, double z )
{
    glPushMatrix( );
        glTranslatef( x, y, z );
        glColor3f( 0.8f, 0.8f, 0.8f );
        
        float i;
        for ( i = 0.0f; i <= 90.0f; i += 20.0f )
        {
            glPushMatrix( );
                glTranslatef( -55.0f, i, 35.0f );
                glScalef( 436.0f, 0.5f, 111.0f );
                glutSolidCube( 1.0f );
            glPopMatrix( );
        }
        
        glPushMatrix( );
            glTranslatef( -55.0f, 0.0f, 35.0f );
            glScalef( 450.0f, 0.5f, 250.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        
    glPopMatrix( );
}

/****************************************************************************************/
/*
    funksioni per ndertimin e universitetit GODINEN
*/
static void godinaA( GLdouble pozX, GLdouble pozY, GLdouble pozZ )
{
    glPushMatrix( );
        glTranslatef( pozX, pozY, pozZ );
        glRotatef( 0.0f, 0.0f, 1.0f, 0.0f );
        
        // kati 1
        // klasat 1
        klasat( -65.0f, 0.0f, -20.0f, 0.0f );
        klasat( 0.0f, 0.0f, -20.0f, 0.0f );
        klasat( 65.0f, 0.0f, -20.0f, 0.0f );
        // klasat 2
        klasat( -65.0f, 0.0f, 90.0f, 180.0f );
        klasat( 0.0f, 0.0f, 90.0f, 180.0f );
        klasat( 65.0f, 0.0f, 90.0f, 180.0f );
        
        // kati 2
        // klasat 1
        klasat( -65.0f, 20.0f, -20.0f, 0.0f );
        klasat( 0.0f, 20.0f, -20.0f, 0.0f );
        klasat( 65.0f, 20.0f, -20.0f, 0.0f );
        // klasat 2
        klasat( -65.0f, 20.0f, 90.0f, 180.0f );
        klasat( 0.0f, 20.0f, 90.0f, 180.0f );
        klasat( 65.0f, 20.0f, 90.0f, 180.0f );
        
        // kati 3
        // klasat 1
        klasat( -65.0f, 40.0f, -20.0f, 0.0f );
        klasat( 0.0f, 40.0f, -20.0f, 0.0f );
        klasat( 65.0f, 40.0f, -20.0f, 0.0f );
        // klasat 2
        klasat( -65.0f, 40.0f, 90.0f, 180.0f );
        klasat( 0.0f, 40.0f, 90.0f, 180.0f );
        klasat( 65.0f, 40.0f, 90.0f, 180.0f );
        
        // kati 4
        // klasat 1
        klasat( -65.0f, 60.0f, -20.0f, 0.0f );
        klasat( 0.0f, 60.0f, -20.0f, 0.0f );
        klasat( 65.0f, 60.0f, -20.0f, 0.0f );
        // klasat 2
        klasat( -65.0f, 60.0f, 90.0f, 180.0f );
        klasat( 0.0f, 60.0f, 90.0f, 180.0f );
        klasat( 65.0f, 60.0f, 90.0f, 180.0f );
        
        // pjesa 1.2
        klasat( -175.0f, 0.0f, -20.0f, 0.0f );
        klasat( -175.0f, 40.0f, -20.0f, 0.0f );
        klasat( -175.0f, 60.0f, -20.0f, 0.0f );
        
        klasat( -195.0f, 0.0f, 90.0f, 180.0f );
        klasat( -195.0f, 40.0f, 90.0f, 180.0f );
        klasat( -195.0f, 60.0f, 90.0f, 180.0f );
        
        klasat( -240.0f, 0.0f, -20.0f, 0.0f );
        klasat( -240.0f, 40.0f, -20.0f, 0.0f );
        klasat( -240.0f, 60.0f, -20.0f, 0.0f );
        
        klasat( -130.0f, 20.0f, 90.0f, 180.0f );
        klasat( -130.0f, 40.0f, 90.0f, 180.0f );
        klasat( -130.0f, 60.0f, 90.0f, 180.0f );
        
        klasat( 130.0f, 40.0f, 90.0f, 180.0f );
        klasat( 130.0f, 60.0f, 90.0f, 180.0f );
        
        
        // muri ndares ne godinen A
        glPushMatrix( );
            glTranslatef( 98.0f, 40.0f, 35.0f );
            glScalef( 1.0f, 80.0f, 110.0f );
            glutSolidCube( 1.0f );
        glPopMatrix( );
        
        // shkallet
        shkallet1( -130.0f, 0.0f, 0.0f );
        shkallet1( -130.0f, 20.0f, 0.0f );
        shkallet1( -130.0f, 40.0f, 0.0f );
        
        shkallet1( 110.0f, 0.0f, 0.0f );
        shkallet1( 110.0f, 20.0f, 0.0f );
        shkallet1( 110.0f, 40.0f, 0.0f );
        
        // sheshet
        miniGroundsGodinaA( 0.0f, 0.0f, 0.0f );
        
        // libraria
        libraria( -207.5f, 20.0f, -20.0f );
        
    glPopMatrix( );
}

/****************************************************************************************/
/*
	Funksioni per inicializimin e efekteve te ndryshme
	dhe te openGL
*/
void init( void )
{
    glClearColor( 0.6f, 0.6f, 1.0f, 1.0f );														// ngjyra e sfondit
    glClearAccum( 0.0f, 0.0f, 0.0f, 0.0f );
	glClearDepth( 1.0 );																			// pastrojme thellesine
    glEnable( GL_CULL_FACE );																		// aktivizojme efektin i objektit
    glCullFace( GL_BACK | GL_FRONT );																// per cdo pjese te objektit
    glEnable( GL_DEPTH_TEST );																	// testojme thellesine
    glEnable( GL_AUTO_NORMAL );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glEnable( GL_BLEND );
    glEnable( GL_LINE_SMOOTH );
    glShadeModel( GL_SMOOTH );																	// i japim shkelqim objektit
    glColorMaterial( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );									// ngjyra e materialit te objektit
    glEnable( GL_COLOR_MATERIAL );																// aktivizimi i ngjyres se objektit
}
/****************************************************************************************/
/*
	Funksioni per shfaqjen e objekteve dhe efekteve ne ekran
*/
void Display( void )
{
	GLfloat i, j;
	
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_ACCUM_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );											// pastron ekranin nga pixelat
    glLoadIdentity( );																			// restarton dritaren
	
	gluLookAt(move_right_left, 0.0f, move_forward_back, move_right_left + speed_right_left, 0.0f, move_forward_back + speed_forward_back, 0.0f, 1.0f, 0.0f);
	
    glMatrixMode( GL_MODELVIEW );
    glPushMatrix( );
    	glTranslatef( 50.0f, -10.0f, -600.0f );
    	glRotatef( rx, 0.0f, 1.0f, 0.0f );
    	rx += 0.05f;
    	
    	
        glEnable(GL_LIGHT0);
    	glEnable(GL_NORMALIZE);
    	glEnable(GL_COLOR_MATERIAL);
    	glEnable(GL_LIGHTING);

        
        GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat light_position[] = {moveLight_Left_right + speedLightLR, 20.0f, moveLight_forward_back + speedLightFB, 0.0f};

		GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
		GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
		GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat high_shininess[] = { 100.0f };

		
    	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    	glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    	glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    	glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    	glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    	
    	godinaA( 0.0f, 0.0f, -25.0f );
    	
    glPopMatrix( );

	glAccum( GL_ACCUM, 1.0f );
    glutSwapBuffers( );																			// ndajme bufferin ne dy pjese
    
}
/****************************************************************************************/
/*
	Funksioni per ndertimin dhe konfigurimin e dritares
	ka si argumenta lartesine dhe gjeresine e dritares
*/
void reshape( int w, int h )
{
    glViewport( 0, 0, ( GLsizei ) w, ( GLsizei ) h );													// permasat e dritares
    glMatrixMode( GL_PROJECTION );																// lloj i pamjes se matrices
    glLoadIdentity( );																			// ngarkon perseri dritaren
    gluPerspective( 40.0f, ( GLfloat ) w / ( GLfloat ) h, 1.0, 10000.0 );								// ndertojme pamjen e te parit
    glMatrixMode( GL_MODELVIEW );																	// lloj tjeter i pamjes se matrices
    glLoadIdentity( );
}
/****************************************************************************************/
/*
	Funksioni per ndertimin e tastieres
*/
void normalKeys( unsigned char key, int x, int y )
{
	GLfloat fraction = 1.0f;
    switch ( key )
    {
        case 27:																				// perfundon programin kur shtyper ESC
            exit( 0 );
            break;
        case 'w':																				// leviz perpara
            move_right_left += speed_right_left * fraction;
            move_forward_back += speed_forward_back * fraction;
            break;
        case 's':																				// leviz mbrapa
            move_right_left -= speed_right_left * fraction;
            move_forward_back -= speed_forward_back * fraction;
            break;
        case 'a':																				// leviz majtas
            angle -= 0.09f;
            speed_right_left = sin(angle);
            speed_forward_back = -cos(angle);
            break;
        case 'd':																				// leviz djathas
            angle += 0.09f;
            speed_right_left = sin(angle);
            speed_forward_back = -cos(angle);
            break;
        case 'p':
			glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
			break;
		case 'l':
			glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
			break;
		default:
			break;
    }
    glutPostRedisplay( );																		// funksion qe sherben per refresh e dritares
}

void specialKey(int key, int x, int y)
{
     switch ( key )
     {
            case GLUT_KEY_RIGHT:
                 speedLightLR -= 5.0f;
                 break;
            case GLUT_KEY_LEFT:
                 speedLightFB += 5.0f;
                 break;
            case GLUT_KEY_UP:
                 speedLightFB -= 5.0f;
                 break;
            case GLUT_KEY_DOWN:
                 speedLightFB += 5.0f;
                 break;
     }
     glutPostRedisplay();
}

/****************************************************************************************/
/*
	Funksioni per rifreskimin e dritares
*/
void idle( void )
{
    glutPostRedisplay( );
}
/****************************************************************************************/
/*
	Funksioni main, kryesori
	therriten te gjithe funksionet
*/
int main( int argc, char* argv[] )
{
	glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL | GLUT_ACCUM );									// modeli i dritares
    glutInitWindowPosition( 10, 10 );																// pozicioni i dritares
    glutInitWindowSize( 800, 600 );																// permasat e dritares
    
	glutCreateWindow( "Simple Workout" );														// titulli i dritares
    init( );																						// funksioni init
    glutDisplayFunc( Display );																	// therritja e funksionit display
    glutReshapeFunc( reshape );																	// therritja e funksionit reshape
    glutIdleFunc( idle );																			// therritja e funksionit idle
    glutKeyboardFunc( normalKeys );																// therritja e funksionit te tastieres
    glutSpecialFunc(specialKey);
    glutMainLoop( );																				// therrit funksionin main    
	return 0;																					// rikthen 0 si return
}
