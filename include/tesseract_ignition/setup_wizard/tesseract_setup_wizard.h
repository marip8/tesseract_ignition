#ifndef TESSERACT_IGNITION_TESSERACT_SETUP_WIZARD_H
#define TESSERACT_IGNITION_TESSERACT_SETUP_WIZARD_H

#ifndef Q_MOC_RUN
  #include <ignition/gui/qt.h>
  #include <ignition/gui/Plugin.hh>
  #include <QQuickWindow>
#endif

namespace tesseract_ignition
{
  namespace gui
  {
    namespace plugins
    {
      class TesseractSetupWizardPrivate;
      class TesseractSetupWizard : public ignition::gui::Plugin
      {
        Q_OBJECT
      public:

        TesseractSetupWizard();
        ~TesseractSetupWizard() override;

        void LoadConfig( const tinyxml2::XMLElement * _pluginElem) override;

        /**
         * @brief Callback trigged when the load button is pressed.
         * @param[in] urdf_filepath The urdf file path.
         * @param[in] srdf_filepath The srdf file path.
         */
        Q_INVOKABLE void onLoad(const QString &urdf_filepath, const QString& srdf_filepath);
        Q_INVOKABLE void onSave(const QString& srdf_filepath);
        Q_INVOKABLE void onAddChainGroup(const QString &group_name, const QString& base_link, const QString& tip_link);

        Q_INVOKABLE void onAddJointGroup(const QString &group_name);
        Q_INVOKABLE void onAddJointGroupJoint(const QString &joint_name);
        Q_INVOKABLE void onRemoveJointGroupJoint(int index);

        Q_INVOKABLE void onAddLinkGroup(const QString &group_name);
        Q_INVOKABLE void onAddLinkGroupLink(const QString &link_name);
        Q_INVOKABLE void onRemoveLinkGroupLink(int index);

        Q_INVOKABLE void onRemoveKinematicGroup(int index);

        Q_INVOKABLE void onGenerateACM(long resolution);
        Q_INVOKABLE void onRemoveACMEntry(int index);

        Q_INVOKABLE void onLoadJointGroup(const QString &group_name);
        Q_INVOKABLE void onJointValue(const QString &joint_name, double joint_value);

        Q_INVOKABLE void onAddUserDefinedJointState(const QString &group_name, const QString &state_name);
        Q_INVOKABLE void onRemoveUserDefinedJointState(int index);

        Q_INVOKABLE void onAddUserDefinedTCP(const QString &group_name,
                                             const QString &tcp_name,
                                             const QVector3D &position,
                                             const QVector3D &orientation);
        Q_INVOKABLE void onRemoveUserDefinedTCP(int index);

        Q_INVOKABLE void onAddGroupOPWKinematics(const QString& group_name,
                                                 double a1, double a2, double b,
                                                 double c1, double c2, double c3, double c4,
                                                 double o1, double o2, double o3, double o4, double o5, double o6,
                                                 int sc1, int sc2, int sc3, int sc4, int sc5, int sc6);
        Q_INVOKABLE void onRemoveGroupOPWKinematics(int index);

      protected:
        Q_INVOKABLE void updateTesseract();
        Q_INVOKABLE void removeGroupStates(const QString& group_name);
        Q_INVOKABLE void removeGroupTCPs(const QString& group_name);
        Q_INVOKABLE void removeGroupOPWKinematics(const QString& group_name);


        /** @brief Used to filter scroll wheel events.
          * @param[in] _o Object that receives the event.
          * @param[in] _event Pointer to the event.
          * @return True if event was handled.
          */
        bool eventFilter(QObject *_o, QEvent *_event) override;

      private:
        /** @brief Pointer to private data */
        std::unique_ptr<TesseractSetupWizardPrivate> data_;
      };
    }
  }
}

#endif
