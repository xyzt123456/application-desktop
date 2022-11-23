import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 6.4
Rectangle
{
    Plugin
    {
        id: mapPlugin
        name: "osm"
    }

    Map
    {
        id:mapView
        anchors.fill: parent
        center: QtPositioning.coordinate(25.6585,125.3658);
        zoomLevel: 15
    }


}
