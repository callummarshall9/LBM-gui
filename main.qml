import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import common.backend 1.0

Window {
    visible: true
    width: 320
    height: 680

    maximumWidth: 320
    maximumHeight: 680
    minimumHeight: 680
    minimumWidth: 320
    title: qsTr("Simulation parameters")

    Backend {
            id: backend
    }

    Grid {
        id: grid
        anchors.rightMargin: 20
        anchors.bottomMargin: 20
        anchors.topMargin: 20
        anchors.leftMargin: 20
        anchors.fill: parent

        Flow {
            id: element
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            spacing: 5
            flow: Flow.TopToBottom
            anchors.rightMargin: 0
            anchors.fill: parent

            Text {
                text: qsTr("Grid size X:")
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 12
            }

            Rectangle {
                width: parent.width
                height: 25
                color: "white"
                border.width: 1
                border.color: "black"
                TextEdit {
                    anchors { left: parent.left; right: parent.right; top: parent.top; bottom: parent.bottom }
                    id: grid_size_x
                    text: backend.gridSizeX
                    font.pointSize: 10
                    onTextChanged: {
                        backend.gridSizeX = parseInt(text)
                    }
                }
            }

            Text {
                text: qsTr("Grid size Y:")
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 12
            }

            Rectangle {
                width: parent.width
                height: 25
                color: "white"
                border.width: 1
                border.color: "black"
                TextEdit {
                    anchors { left: parent.left; right: parent.right; top: parent.top; bottom: parent.bottom }
                    id: grid_size_y
                    text: backend.gridSizeY
                    font.pointSize: 10
                    onTextChanged: {
                        backend.gridSizeY = parseInt(text);
                    }
                }
            }

            Text {
                text: qsTr("Grid size Z:")
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 12
            }

            Rectangle {
                width: parent.width
                height: 25
                color: "white"
                border.width: 1
                border.color: "black"
                TextInput {
                    anchors { left: parent.left; right: parent.right; top: parent.top; bottom: parent.bottom }
                    id: grid_size_z
                    text: backend.gridSizeZ
                    font.pointSize: 10
                    onTextChanged: {
                        backend.gridSizeZ = parseInt(text);
                    }
                }
            }

            Text {
                text: qsTr("Velocity set:")
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 12
            }

            ComboBox {
                id: velocity_set
                width: parent.width
                height:25
                font.pointSize: 10
                model: ["D2Q9", "D3Q15", "D3Q27"]
                currentIndex: backend.velocitySetSelectedIndex
                onCurrentIndexChanged: {
                    backend.velocitySetSelectedIndex = currentIndex
                }
            }

            Text {
                text: qsTr("Speed of sound (c_s):")
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 12
            }

            Rectangle {
                width: parent.width
                height: 25
                color: "white"
                border.width: 1
                border.color: "black"
                TextEdit {
                    anchors { left: parent.left; right: parent.right; top: parent.top; bottom: parent.bottom }
                    id: c_s
                    text: backend.speedOfSound
                    font.pointSize: 10
                    onTextChanged: {
                        backend.speedOfSound = parseFloat(text)
                    }
                }
            }

            Text {
                text: qsTr("Relaxation time (tau):")
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 12
            }

            Rectangle {
                width: parent.width
                height: 25
                color: "white"
                border.width: 1
                border.color: "black"
                TextEdit {
                    anchors { left: parent.left; right: parent.right; top: parent.top; bottom: parent.bottom }
                    id: tau
                    text: backend.relaxationTime
                    font.pointSize: 10
                    onTextChanged: {
                        backend.relaxationTime = parseFloat(text)
                    }
                }
            }

            Text {
                text: qsTr("Boundary conditions:")
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 12
            }

            ComboBox {
                id: boundary_conditions
                width: parent.width
                height:25
                font.pointSize: 10
                model: ["Periodic", "Couette flow", "Lees-Edwards"]
                currentIndex: backend.boundaryConditionSelectedIndex
                onCurrentIndexChanged: {
                    backend.boundaryConditionSelectedIndex = currentIndex
                }
            }

            Text {
                text: qsTr("Shear rate (gamma dot):")
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 12
            }


            Rectangle {
                width: parent.width
                height: 25
                color: "white"
                border.width: 1
                border.color: "black"
                TextEdit {
                    anchors { left: parent.left; right: parent.right; top: parent.top; bottom: parent.bottom }
                    id: gamma_dot
                    text: backend.shearRate
                    font.pointSize: 10
                    onTextChanged: {
                        backend.shearRate = parseFloat(text)
                    }
                }
            }

            Text {
                text: qsTr("Save a CSV file containing the density \nand velocity within the domain every set\nof steps:")
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 12
            }

            Rectangle {
                width: parent.width
                height: 25
                color: "white"
                border.width: 1
                border.color: "black"
                TextEdit {
                    anchors { left: parent.left; right: parent.right; top: parent.top; bottom: parent.bottom }
                    id: save_every
                    text: backend.saveEvery
                    font.pointSize: 10
                    onTextChanged: {
                        backend.saveEvery = parseInt(text)
                    }
                }
            }

            Text {
                text: qsTr("Number of total timesteps to execute in\nsimulation:")
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 12
            }

            Rectangle {
                width: parent.width
                height: 25
                color: "white"
                border.width: 1
                border.color: "black"
                TextEdit {
                    anchors { left: parent.left; right: parent.right; top: parent.top; bottom: parent.bottom }
                    id: number_of_steps
                    text: backend.numberOfSteps
                    font.pointSize: 10
                    onTextChanged: {
                        backend.numberOfSteps = parseInt(text)
                    }
                }
            }

            Row {
                width: parent.width
                height: 30
                layoutDirection: Qt.RightToLeft
                Button {
                    height: 30
                    id: button
                    text: qsTr("Save")
                    transformOrigin: Item.Center
                    checked: false
                    checkable: false
                    highlighted: false
                    flat: false
                    onClicked: {
                        savingBox.text = "Saving"
                        savingBox.visible = true;
                        savingBox.checked = false;
                        if(backend.save()) {
                            savingBox.checked = true;
                            savingBox.text = "Saved!"
                        } else {
                            savingBox.checked = false;
                        }
                    }
                }
            }


        }
    }

    CheckBox {
        id: savingBox
        x: 20
        y: 628
        width: 153
        height: 40
        text: qsTr("Saving")
        checkable: false
        visible: false
    }


}





/*##^## Designer {
    D{i:2;anchors_height:400;anchors_width:400;anchors_x:120;anchors_y:40}D{i:1;anchors_height:400;anchors_width:400;anchors_x:269;anchors_y:66}
}
 ##^##*/
