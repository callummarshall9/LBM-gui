#include "backend.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

Backend::Backend(QObject *parent) : QObject(parent),mGridSizeX(1),mGridSizeY(1),mGridSizeZ(1),
    mVelocitySetSelectedIndex(1),mSpeedOfSound(0.0),mRelaxationTime(0.0),
    mBoundaryConditionSelected(0),mShearRate(0.5),mOptionsLoaded(false),
    mSaveEvery(200),mNumberOfSteps(1000)
{
    QFile options("options.json");
    if(!options.open(QIODevice::ReadOnly)) {
        mOptionsLoaded = false;
        return;
    }
    QByteArray optionData = options.readAll();
    QJsonDocument optionsDocument(QJsonDocument::fromJson(optionData));
    QJsonObject optionsObject = optionsDocument.object();
    QJsonArray gridSize = optionsObject["grid_size"].toArray();
    mGridSizeX = gridSize[0].toInt();
    mGridSizeY = gridSize[1].toInt();
    mGridSizeZ = gridSize[2].toInt();
    int saveEvery = optionsObject["save_every"].toInt();
    mSaveEvery = saveEvery;

    double speedOfSound = optionsObject["c_s"].toDouble();
    mSpeedOfSound = speedOfSound;

    QString velocitySet = optionsObject["velocity_set"].toString();
    if(velocitySet == "D2Q9") {
        mVelocitySetSelectedIndex = 0;
    } else if(velocitySet == "D3Q15") {
        mVelocitySetSelectedIndex = 1;
    } else if(velocitySet == "D3Q27") {
        mVelocitySetSelectedIndex = 2;
    }
    double tau = optionsObject["tau"].toDouble();
    mRelaxationTime = tau;
    double gammaDot = optionsObject["gamma_dot"].toDouble();
    mShearRate = gammaDot;
    QString boundaryConditions = optionsObject["boundary_conditions"].toString();
    if(boundaryConditions == "periodic") {
        mBoundaryConditionSelected = 0;
    } else if(boundaryConditions == "couette") {
        mBoundaryConditionSelected = 1;
    } else if(boundaryConditions == "lees_edwards") {
        mBoundaryConditionSelected = 2;
    }
    int numberOfSteps = optionsObject["n_steps"].toInt();
    mNumberOfSteps = numberOfSteps;
    options.close();
}


int Backend::gridSizeX() {
    return mGridSizeX;
}

int Backend::gridSizeY() {
    return mGridSizeY;
}

int Backend::gridSizeZ() {
    return mGridSizeZ;
}

int Backend::velocitySetSelected() {
    return mVelocitySetSelectedIndex;
}

double Backend::speedOfSound() {
    return mSpeedOfSound;
}

double Backend::relaxationTime() {
    return mRelaxationTime;
}

int Backend::boundaryConditionSelected() {
    return mBoundaryConditionSelected;
}

double Backend::shearRate() {
    return mShearRate;
}

bool Backend::optionsLoaded() {
    return mOptionsLoaded;
}

int Backend::saveEvery() {
    return mSaveEvery;
}

int Backend::numberOfSteps() {
    return mNumberOfSteps;
}

bool Backend::save() {
    QJsonObject saveObject;
    QJsonArray gridSize;
    QJsonValue gridSizeXValue(gridSizeX());
    gridSize.push_back(gridSizeXValue);
    QJsonValue gridSizeYValue(gridSizeY());
    gridSize.push_back(gridSizeYValue);
    QJsonValue gridSizeZValue(gridSizeZ());
    gridSize.push_back(gridSizeZValue);
    saveObject["grid_size"] = gridSize;
    QJsonValue saveEveryValue(saveEvery());
    saveObject["save_every"] = saveEveryValue;
    QJsonValue speedOfSoundValue(speedOfSound());
    saveObject["c_s"] = speedOfSoundValue;

    if(velocitySetSelected() == 0) {
        QJsonValue velocitySetValue("D2Q9");
        saveObject["velocity_set"] = velocitySetValue;
    } else if(velocitySetSelected() == 1) {
        QJsonValue velocitySetValue("D3Q15");
        saveObject["velocity_set"] = velocitySetValue;
    } else if(velocitySetSelected() == 2) {
        QJsonValue velocitySetValue("D3Q27");
        saveObject["velocity_set"] = velocitySetValue;
    }
    QJsonValue relaxationTimeValue(relaxationTime());
    saveObject["tau"] = relaxationTimeValue;
    QJsonValue shearRateValue(shearRate());
    saveObject["gamma_dot"] = shearRateValue;

    if(boundaryConditionSelected() == 0) {
        QJsonValue boundaryConditionValue("periodic");
        saveObject["boundary_conditions"] = boundaryConditionValue;
    } else if(boundaryConditionSelected() == 1) {
        QJsonValue boundaryConditionValue("couette");
        saveObject["boundary_conditions"] = boundaryConditionValue;
    } else if(boundaryConditionSelected() == 2) {
        QJsonValue boundaryConditionValue("lees_edwards");
        saveObject["boundary_conditions"] = boundaryConditionValue;
    }
    QJsonValue numberOfStepsValue(numberOfSteps());
    saveObject["n_steps"] = numberOfStepsValue;

    QFile optionsFile("options.json");
    if(optionsFile.exists()) {
        if(!optionsFile.remove()) {
            qDebug() << "ERROR: OPTIONS FILE CANNOT BE REMOVED.";
            return false;
        }
    }
    QJsonDocument optionsDocument(saveObject);
    if(!optionsFile.open(QIODevice::WriteOnly)) {
        qDebug() << "ERROR: OPTIONS FILE CANNOT BE CREATED.";
        return false;
    }
    optionsFile.write(optionsDocument.toJson());
    optionsFile.close();
    return true;
}

void Backend::setGridSizeX(int gridSizeX) {
    mGridSizeX = gridSizeX;
}

void Backend::setGridSizeY(int gridSizeY) {
    mGridSizeY = gridSizeY;
}

void Backend::setGridSizeZ(int gridSizeZ) {
    mGridSizeZ = gridSizeZ;
}

void Backend::setVelocitySetSelected(int velocitySetSelected) {
    mVelocitySetSelectedIndex = velocitySetSelected;
}

void Backend::setSpeedOfSound(double speedOfSound) {
    mSpeedOfSound = speedOfSound;
}

void Backend::setRelaxationTime(double relaxationTime) {
    mRelaxationTime = relaxationTime;
}

void Backend::setBoundaryConditionSelected(int boundaryConditionSelected) {
    mBoundaryConditionSelected = boundaryConditionSelected;
}

void Backend::setShearRate(double shearRate) {
    mShearRate = shearRate;
}

void Backend::setSaveEvery(int saveEvery) {
    mSaveEvery = saveEvery;
}

void Backend::setNumberOfSteps(int numberOfSteps) {
    mNumberOfSteps = numberOfSteps;
}
