#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int gridSizeX READ gridSizeX WRITE setGridSizeX)
    Q_PROPERTY(int gridSizeY READ gridSizeY WRITE setGridSizeY)
    Q_PROPERTY(int gridSizeZ READ gridSizeZ WRITE setGridSizeZ)
    Q_PROPERTY(int velocitySetSelectedIndex READ velocitySetSelected WRITE setVelocitySetSelected)
    Q_PROPERTY(double speedOfSound READ speedOfSound WRITE setSpeedOfSound)
    Q_PROPERTY(double relaxationTime READ relaxationTime WRITE setRelaxationTime)
    Q_PROPERTY(int boundaryConditionSelectedIndex READ boundaryConditionSelected WRITE setBoundaryConditionSelected)
    Q_PROPERTY(double shearRate READ shearRate WRITE setShearRate)
    Q_PROPERTY(bool optionsLoaded READ optionsLoaded)
    Q_PROPERTY(int saveEvery READ saveEvery WRITE setSaveEvery)
    Q_PROPERTY(int numberOfSteps READ numberOfSteps WRITE setNumberOfSteps)
public:
    explicit Backend(QObject *parent = nullptr);
    Q_INVOKABLE bool save();
    int gridSizeX();
    int gridSizeY();
    int gridSizeZ();
    int velocitySetSelected();
    double speedOfSound();
    double relaxationTime();
    int boundaryConditionSelected();
    double shearRate();
    bool optionsLoaded();
    int saveEvery();
    int numberOfSteps();
    void setGridSizeX(int gridSizeX);
    void setGridSizeY(int gridSizeY);
    void setGridSizeZ(int gridSizeZ);
    void setVelocitySetSelected(int velocitySetSelected);
    void setSpeedOfSound(double speedOfSound);
    void setRelaxationTime(double relaxationTime);
    void setBoundaryConditionSelected(int boundaryConditionSelected);
    void setShearRate(double shearRate);
    void setSaveEvery(int saveEvery);
    void setNumberOfSteps(int numberOfSteps);
private:
    int mGridSizeX;
    int mGridSizeY;
    int mGridSizeZ;
    int mVelocitySetSelectedIndex;
    double mSpeedOfSound;
    double mRelaxationTime;
    int mBoundaryConditionSelected;
    double mShearRate;
    bool mOptionsLoaded;
    int mSaveEvery;
    int mNumberOfSteps;
signals:

public slots:
};

#endif // BACKEND_H
