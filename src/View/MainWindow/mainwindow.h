﻿#pragma once

// Qt
#include <QMainWindow>
#include <QTimer>

// STL
#include <string>
#include <mutex>

// Custom
#include "../src/Model/OutputTextType.h"

// ============== Network ==============
// Sockets and stuff
#include <winsock2.h>

// Adress translation
#include <ws2tcpip.h>

// Winsock 2 Library
#pragma comment(lib,"Ws2_32.lib")



class connectWindow;
class Controller;
class QMouseEvent;
class QTimer;
class QMenu;
class QAction;
class QSystemTrayIcon;

namespace Ui
{
    class MainWindow;
}



// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);

    void connectTo                      (std::string adress, std::string port, std::string userName);

        void  printOutput               (std::string text, SilentMessageColor messageColor, bool bEmitSignal = false);
        void  printOutputW              (std::wstring text, SilentMessageColor messageColor, bool bEmitSignal = false);
        void  printUserMessage          (std::string timeInfo, std::wstring message, SilentMessageColor messageColor, bool bEmitSignal = false);
        void  enableInteractiveElements (bool bMenu, bool bTypeAndSend);
        void  setOnlineUsersCount       (int onlineCount);
        void  setPingToUser             (std::string userName, int ping);
        void  addNewUserToList          (std::string name);
        void  deleteUserFromList        (std::string name, bool bDeleteAll = false);
        void  showUserDisconnectNotice  (std::string name, SilentMessageColor messageColor, bool bUserLost);
        void  showUserConnectNotice     (std::string name, SilentMessageColor messageColor);
        void  showMessageBox            (char type, std::string message);
        void  clearTextEdit             ();
        void  saveUserName              (std::string userName);

    ~MainWindow();

signals:

    void signalShowUserConnectNotice(std::string name, SilentMessageColor messageColor);
    void signalShowUserDisconnectNotice(std::string name, SilentMessageColor messageColor, bool bUserLost);
    void signalTypeOnScreen(QString text, SilentMessageColor messageColor, bool bUserMessage = false);
    void signalShowMessage(char type, std::string message);
    void signalSetPingToUser(std::string userName, int ping);
    void signalEnableInteractiveElements(bool bMenu, bool bTypeAndSend);

public slots:

    void slotSetPushToTalkButton(int iKey, unsigned short int volume);

protected:

    void hideEvent(QHideEvent* event);
    void closeEvent(QCloseEvent *event);


private slots:

    // Context menu in list
    void slotChangeUserVolume();

    void slotSetNewUserVolume(QString userName, float fVolume);

    void slotShowMessage(char type, std::string message);
    void slotSetPingToUser(std::string userName, int ping);
    void typeSomeOnScreen(QString text, SilentMessageColor messageColor, bool bUserMessage = false);
    void slotEnableInteractiveElements(bool bMenu, bool bTypeAndSend);
    void slotTrayIconActivated();
    void slotShowUserDisconnectNotice(std::string name, SilentMessageColor messageColor, bool bUserLost);
    void slotShowUserConnectNotice(std::string name, SilentMessageColor messageColor);

    void on_actionAbout_2_triggered();
    void on_actionConnect_triggered();
    void on_actionDisconnect_triggered();
    void on_actionSettings_triggered();

    void on_pushButton_clicked();
    void on_plainTextEdit_2_textChanged();
    void on_listWidget_2_customContextMenuRequested(const QPoint &pos);

private:

    void checkIfSettingsExist();
    void closeApp();



    // ------------------------------------------


    Ui::MainWindow*  ui;
    connectWindow*   pConnectWindow;
    Controller*      pController;


    // Context menu in list
    QMenu*           pMenuContextMenu;
    QAction*         pActionChangeVolume;


    QTimer*          pTimer;


    QSystemTrayIcon* pTrayIcon;


    std::mutex       mtxPrintOutput;


    QString          outputHTMLmessageStart;
    QString          outputHTMLmessageEnd;
};