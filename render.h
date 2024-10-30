#include "object.cpp"
#include <GL/glut.h>

#pragma region Group NavBar

Object NavBar = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object appIcon = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object appNameText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object dashboardIcon = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object dashBoardText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object settingsIcon = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object settingsText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object controlIcon = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object controlText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderNavBar()
{
    glColor4f(COLOUR_PINK);
    NavBar.translate(0, 510);
    NavBar.drawRoundedRectFill(WINDOWS_WIDTH, 130, 45);
}

void renderAppNameText()
{
    glColor4f(COLOUR_BLACK);
    appNameText.drawText(125, 1015, "SmartHomeControl", 3.8f, 5.5f);
}

void renderDashboardText()
{
    glColor4f(COLOUR_BLACK);
    dashBoardText.drawText(1200, 1016, "Dashboard", 3.0f, 3.5f);
}

void renderSettingsIcon()
{
    glColor4f(COLOUR_BLACK);
    settingsIcon.translate(505, 490);
    settingsIcon.drawTorus(12, 6, 0, 365);
    // Top
    settingsIcon.drawIrregularRectangle(
        1458.0f, 1043.0f, // Bottom Left
        1473.0f, 1043.0f, // Bottom Right
        1468.0f, 1050.0f, // Top Right   
        1462.0f, 1050.0f  // Top Left
    );
    // Bottom
    settingsIcon.drawIrregularRectangle(
        1458.0f, 1000.0f, // Bottom Left
        1473.0f, 1000.0f, // Bottom Right
        1468.0f, 1007.0f, // Top Right   
        1462.0f, 1007.0f  // Top Left
    );

}

void renderSettingsText()
{
    glColor4f(COLOUR_BLACK);
    settingsText.drawText(1490, 1016, "Settings", 3.0f, 3.5f);
}

void renderControlText()
{
    glColor4f(COLOUR_WHITE);
    controlText.drawText(1720, 1016, "Control", 3.0f, 3.5f);
}

#pragma endregion Group NavBar

#pragma region Group Dashboard

Object Dashboard1 = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object Dashboard2 = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object Dashboard3Button1 = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object Dashboard3Button2 = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object Dashboard3Button3 = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object Dashboard3Button4 = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object Dashboard3Button5 = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object Dashboard3Button6 = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object Dashboard3Button7 = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object Dashboard3Button8 = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object Dashboard4Control1 = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object Dashboard4Control2 = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderDashboard1()
{
    glColor4f(COLOUR_GREY_PINK);
    Dashboard1.translate(-470, 190);
    Dashboard1.drawRoundedRectFill(910, 470, 45);
}

void renderDashboard2()
{
    glColor4f(COLOUR_ORANGE_PINK);
    Dashboard2.translate(470, 190);
    Dashboard2.drawRoundedRectFill(910, 470, 45);
}

void renderDashboard3Button1()
{
    glColor4f(COLOUR_DARK_PINK);
    Dashboard3Button1.translate(-819, -175);
    Dashboard3Button1.drawRoundedRectFill(204, 220, 45);
}

void renderDashboard3Button2()
{
    glColor4f(COLOUR_LIGHT_GREY);
    Dashboard3Button2.translate(-586, -175);
    Dashboard3Button2.drawRoundedRectFill(204, 220, 45);
}

void renderDashboard3Button3()
{
    glColor4f(COLOUR_LIGHT_GREY);
    Dashboard3Button3.translate(-353, -175);
    Dashboard3Button3.drawRoundedRectFill(204, 220, 45);
}

void renderDashboard3Button4()
{
    glColor4f(COLOUR_LIGHT_GREY);
    Dashboard3Button4.translate(-120, -175);
    Dashboard3Button4.drawRoundedRectFill(204, 220, 45);
}

void renderDashboard3Button5()
{
    glColor4f(COLOUR_LIGHT_GREY);
    Dashboard3Button5.translate(-819, -410);
    Dashboard3Button5.drawRoundedRectFill(204, 220, 45);
}

void renderDashboard3Button6()
{
    glColor4f(COLOUR_LIGHT_GREY);
    Dashboard3Button6.translate(-586, -410);
    Dashboard3Button6.drawRoundedRectFill(204, 220, 45);
}

void renderDashboard3Button7()
{
    glColor4f(COLOUR_LIGHT_GREY);
    Dashboard3Button7.translate(-353, -410);
    Dashboard3Button7.drawRoundedRectFill(204, 220, 45);
}

void renderDashboard3Button8()
{
    glColor4f(COLOUR_DARK_PINK);
    Dashboard3Button8.translate(-120, -410);
    Dashboard3Button8.drawRoundedRectFill(204, 220, 45);
}

void renderDashboard4Control1()
{
    glColor4f(COLOUR_LIGHT_YELLOW);
    Dashboard4Control1.translate(230, -295);
    Dashboard4Control1.drawRoundedRectFill(425, 450, 45);
}

void renderDashboard4Control2()
{
    glColor4f(COLOUR_LIGHT_PINK);
    Dashboard4Control2.translate(705, -295);
    Dashboard4Control2.drawRoundedRectFill(425, 450, 45);
}

#pragma endregion Group Dashboard

#pragma region Group Dashboard1

Object WelcomeMessages = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object WeatherIcon = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object WeatherInfoText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object HumidityIcon = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object HumidityInfoText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object TemperatureIcon = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object TemperatureInfoText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object AddData = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object AddDataText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderWelcomeMessages()
{
    glColor4f(COLOUR_BLACK);
    WelcomeMessages.drawText(80, 900, "Hello, Rei!", 3.2f, 4.8f);
    glColor4f(COLOUR_LIGHT_BLACK);
    WelcomeMessages.drawText(80, 850, "Welcome home Rei. The weather today is quite hot,", 2.2f, 3.2f);
    WelcomeMessages.drawText(80, 810, "please remember to keep yourself hydrated!", 2.2f, 3.2f);

}

void renderWeatherInfoText()
{
    glColor4f(COLOUR_BLACK);
    WeatherInfoText.drawText(125, 595, "30", 3.6f, 5.3f);
    WeatherInfoText.translate(-760, 95);
    WeatherInfoText.drawTorus(6, 4, 0, 365);
    WeatherInfoText.drawText(110, 555, "Weather", 2.2f, 3.2f);
    WeatherInfoText.drawText(120, 515, "Sunny", 2.2f, 3.2f);
}

void renderHumidityInfoText()
{
    glColor4f(COLOUR_BLACK);
    HumidityInfoText.drawText(330, 595, "45%", 3.6f, 5.3f);
    HumidityInfoText.drawText(325, 555, "Outdoor", 2.2f, 3.2f);
    HumidityInfoText.drawText(320, 515, "Humidity", 2.2f, 3.2f);
}

void renderTemperatureInfoText()
{
    glColor4f(COLOUR_BLACK);
    TemperatureInfoText.drawText(590, 595, "22", 3.6f, 5.3f);
    TemperatureInfoText.translate(-295, 95);
    TemperatureInfoText.drawTorus(6, 4, 0, 365);
    TemperatureInfoText.drawText(580, 555, "Indoor", 2.2f, 3.2f);
    TemperatureInfoText.drawText(530, 515, "Temperature", 2.2f, 3.2f);
}


void renderAddDataText()
{
    glColor4f(COLOUR_GREY);
    AddDataText.drawText(805, 555, "Add", 2.2f, 3.2f);
    AddDataText.drawText(800, 515, "Data", 2.2f, 3.2f);
}

#pragma endregion Group Dashboard1

#pragma region Group Dashboard2

Object TemperatureLabelText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object TemperatureInfoDashboard = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object TemperatureInfoDashboardText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object TemperatureSubInfoText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object PowerUsageLabelText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object PowerUsageInfoDashboard = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object PowerUsageSubInfoText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderTemperatureLabelText()
{
    glColor4f(COLOUR_BLACK);
    TemperatureLabelText.drawText(1110, 900, "Temperature", 3.2f, 4.8f);
}

void renderTemperatureInfoDashboard()
{
    // Temperature Gauge
    TemperatureInfoDashboard.translate(280, 160);
    glColor4f(COLOUR_DARK_GREY);
    TemperatureInfoDashboard.drawTorus(150, 17, 230, 130); // Outer ring (use blue color)
    glColor4f(COLOUR_LIGHT_BLUE);
    TemperatureInfoDashboard.drawTorus(150, 17, 230, 70); // Outer ring (use blue color)
    glColor4f(COLOUR_WHITE);
    TemperatureInfoDashboard.drawCircle(120, 0, 360);     // Inner circle (white)
    glColor4f(COLOUR_BLACK);
    TemperatureInfoDashboard.drawTorus(108, 7, 0, 360); // Inner ring (black)
}

void renderTemperatureInfoDashboardText()
{
    glColor4f(COLOUR_BLACK);
    TemperatureInfoDashboardText.drawText(1190, 680, "22", 5.0f, 7.0f);
    TemperatureInfoDashboardText.translate(330, 190);
    TemperatureInfoDashboardText.drawTorus(8, 5, 0, 365);
    TemperatureInfoDashboardText.drawText(1230, 625, "c", 3.2f, 4.2f);
}

void renderPowerUsageLabelText()
{
    glColor4f(COLOUR_BLACK);
    PowerUsageLabelText.drawText(1550, 900, "Power", 3.2f, 4.8f);
}

void renderTemperatureSubInfoText()
{
    glColor4f(COLOUR_BLACK);
    TemperatureSubInfoText.drawText(1125, 515, "22", 2.2f, 3.2f);
    TemperatureSubInfoText.translate(210, -2);
    TemperatureSubInfoText.drawTorus(4, 3, 0, 365);
    TemperatureSubInfoText.drawText(1190, 515, "in 20 min", 2.2f, 3.2f);
}

void renderPowerUsageSubInfoText()
{
    glColor4f(COLOUR_BLACK);
    PowerUsageSubInfoText.drawText(1520, 515, "Saving 1.87$", 2.2f, 3.2f);
}

#pragma endregion Group Dashboard2

#pragma region Group Dashboard3

Object LightText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object LightButton = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object HeatText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object HeatButton = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object AirConditionerText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object AirConditionerButton = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object CameraText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object CameraButton = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object DoorText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object DoorButton = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object AlarmText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object AlarmButton = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object BlindsText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object BlindsButton = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object MusicText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object MusicButton = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderLightText()
{
    glColor4f(COLOUR_BLACK);
    LightText.drawText(100, 300, "Lights", 2.2f, 3.2f);
}

void renderHeatText()
{
    glColor4f(COLOUR_BLACK);
    HeatText.drawText(325, 300, "Heating", 2.2f, 3.2f);
}

void renderAirConditionerText()
{
    glColor4f(COLOUR_BLACK);
    AirConditionerText.drawText(590, 325, "Air", 2.2f, 3.2f);
    AirConditionerText.drawText(530, 285, "Conditioner", 2.2f, 3.2f);
}

void renderCameraText()
{
    glColor4f(COLOUR_BLACK);
    CameraText.drawText(780, 300, "Cameras", 2.2f, 3.2f);
}

void renderDoorText()
{
    glColor4f(COLOUR_BLACK);
    DoorText.drawText(100, 60, "Doors", 2.2f, 3.2f);
}

void renderAlarmText()
{
    glColor4f(COLOUR_BLACK);
    AlarmText.drawText(330, 60, "Alarms", 2.2f, 3.2f);
}

void renderBlindsText()
{
    glColor4f(COLOUR_BLACK);
    BlindsText.drawText(570, 60, "Blinds", 2.2f, 3.2f);
}

void renderMusicText()
{
    glColor4f(COLOUR_BLACK);
    MusicText.drawText(805, 60, "Music", 2.2f, 3.2f);
}

#pragma endregion Group Dashboard3

#pragma region Group Dashboard4Control1

Object LightingText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object BulbIcon = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object LightControl = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object RoomControl = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object RoomControlText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderLightingText()
{
    glColor4f(COLOUR_BLACK);
    LightingText.drawText(1010, 410, "Lighting", 3.2f, 4.8f);
}

void renderRoomControlText()
{
    glColor4f(COLOUR_BLACK);
    RoomControlText.drawText(1150, 55, "Studio", 2.2f, 3.2f);
}

#pragma endregion Group Dashboard4Control1

#pragma region Group Dashboard4Control2

Object MusicPlayerText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object MusicIcon = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object MusicInfoText = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object MusicControl = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderMusicPlayerText()
{
    glColor4f(COLOUR_BLACK);
    MusicPlayerText.drawText(1488, 410, "Music Player", 3.2f, 4.8f);
}

void renderMusicInfoText()
{
    glColor4f(COLOUR_BLACK);
    MusicInfoText.drawText(1550, 150, "Now Playing-", 2.5f, 4.0f);
    MusicInfoText.drawItalicText(1630, 105, "Koala", 2.2f, 0.2f);
}

void renderMusicControl() {
    glColor4f(COLOUR_BLACK);
    MusicControl.translate(250, 500);
}

#pragma endregion Group Dashboard4Control2

#pragma region More Icon

Object MoreIcon = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderMoreIcon1()
{
    glColor4f(COLOUR_BLACK);
    MoreIcon.translate(-60, 380);
    MoreIcon.drawCircle(4, 0, 360);

    MoreIcon.translate(11, 0);
    MoreIcon.drawCircle(4, 0, 360);

    MoreIcon.translate(11, 0);
    MoreIcon.drawCircle(4, 0, 360);
}

void renderMoreIcon2()
{
    glColor4f(COLOUR_BLACK);
    MoreIcon.translate(915, 0);
    MoreIcon.drawCircle(4, 0, 360);

    MoreIcon.translate(11, 0);
    MoreIcon.drawCircle(4, 0, 360);

    MoreIcon.translate(11, 0);
    MoreIcon.drawCircle(4, 0, 360);
}

void renderMoreIcon3()
{
    glColor4f(COLOUR_BLACK);
    MoreIcon.translate(-505, -495);
    MoreIcon.drawCircle(4, 0, 360);

    MoreIcon.translate(11, 0);
    MoreIcon.drawCircle(4, 0, 360);

    MoreIcon.translate(11, 0);
    MoreIcon.drawCircle(4, 0, 360);
}

void renderMoreIcon4()
{
    glColor4f(COLOUR_BLACK);
    MoreIcon.translate(455, 0);
    MoreIcon.drawCircle(4, 0, 360);

    MoreIcon.translate(11, 0);
    MoreIcon.drawCircle(4, 0, 360);

    MoreIcon.translate(11, 0);
    MoreIcon.drawCircle(4, 0, 360);
}


#pragma endregion More Icon