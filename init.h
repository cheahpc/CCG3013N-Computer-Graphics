// Include rendering functions
#include "render.h"
#include "colour.h"
#include <GL/gl.h>
#include "dimen.h"
#include <GL/glut.h>

void renderMaster()
{
    // Render code here
    renderNavBar();     // Render the navigation bar on top
    renderAppNameText(); // Render the app name text
    renderDashboardText(); // Render the dashboard text
    renderSettingsIcon(); // Render the settings icon
    renderSettingsText(); // Render the settings text
    renderControlText(); // Render the control text
    renderDashboard1(); // Render the dashboard 1
    renderWelcomeMessages(); // Render the welcome messages
    renderWeatherInfoText(); // Render the weather info text
    renderHumidityInfoText(); // Render the humidity info text
    renderTemperatureInfoText(); // Render the temperature info text
    renderAddDataText(); // Render the add data text
    renderDashboard2(); // Render the dashboard 2
    renderTemperatureLabelText(); // Render the temperature label text
    renderTemperatureInfoDashboard(); // Render the temperature info dashboard
    renderTemperatureInfoDashboardText(); // Render the temperature info dashboard text
    renderTemperatureSubInfoText(); // Render the temperature sub info text
    renderPowerUsageLabelText(); // Render the power usage label text
    renderPowerUsageSubInfoText(); // Render the power usage sub info text
    renderDashboard3Button1(); // Render the dashboard 3 button 1
    renderDashboard3Button2(); // Render the dashboard 3 button 2
    renderDashboard3Button3(); // Render the dashboard 3 button 3
    renderDashboard3Button4(); // Render the dashboard 3 button 4
    renderDashboard3Button5(); // Render the dashboard 3 button 5
    renderDashboard3Button6(); // Render the dashboard 3 button 6
    renderDashboard3Button7(); // Render the dashboard 3 button 7
    renderDashboard3Button8(); // Render the dashboard 3 button 8
    renderLightText(); // Render the lighting text
    renderHeatText(); // Render the heat text
    renderAirConditionerText(); // Render the air conditioner text
    renderCameraText(); // Render the camera text
    renderDoorText(); // Render the door text
    renderAlarmText(); // Render the alarm text
    renderBlindsText(); // Render the blinds text
    renderMusicText(); // Render the music text
    renderDashboard4Control1(); // Render the dashboard 4 control 1
    renderLightingText(); // Render the lighting text
    renderRoomControlText(); // Render the room control text
    renderDashboard4Control2(); // Render the dashboard 4 control 2
    renderMusicInfoText(); // Render the music info text
    renderMusicPlayerText(); // Render the music player text
    renderMoreIcon1(); // Render the more icon1
    renderMoreIcon2(); // Render the more icon2
    renderMoreIcon3(); // Render the more icon3
    renderMoreIcon4(); // Render the more icon4

    glFlush();  // Clear all GL executions.
    glFinish(); // Block until all GL executions are completed.
}

void init()
{
    // Initialize the windows
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);                   // Set the display mode to single buffer and RGBA
    glutInitWindowSize(WINDOWS_WIDTH, WINDOWS_HEIGHT);              // Set the windows size
    glutInitWindowPosition(WINDOWS_CENTER_Y, WINDOWS_CENTER_Y);     // Set the windows position
    glutCreateWindow("Smart Home Control System"); // Set the windows title
    glutFullScreen();                                               // Set the windows to full screen

    // Initialize the rendering context
    glClearColor(COLOUR_WHITE);                   // Set the background color to white, any area not rendered will be white
    glMatrixMode(GL_PROJECTION);                       // Set the matrix mode to projection
    glEnable(GL_LINE_SMOOTH);                          // Enables line anti-aliasing
    glEnable(GL_BLEND);                                // Enable for proper transparency render
    glDisable(GL_DEPTH_TEST);                          // Disable depth testing for overlap object. Use for transparency object involved
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Enable transparency
    Object::glEndReset();                              // Reset the matrix
    glClear(GL_COLOR_BUFFER_BIT);                      // Load frame buffer
}
