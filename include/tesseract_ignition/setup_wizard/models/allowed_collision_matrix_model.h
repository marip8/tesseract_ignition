#ifndef TESSERACT_IGNITION_ALLOWED_COLLISION_MATRIX_MODEL_H
#define TESSERACT_IGNITION_ALLOWED_COLLISION_MATRIX_MODEL_H

#ifndef Q_MOC_RUN
#include <tesseract_environment/core/environment.h>
#include <QStandardItemModel>
#include <QMetaType>
#endif

namespace tesseract_ignition
{
class AllowedCollisionMatrixModel : public QStandardItemModel
{
    Q_OBJECT
public:
  enum AllowedCollisionMatrixRoles {
      Link1Role = Qt::UserRole + 1,
      Link2Role = Qt::UserRole + 2,
      ReasonRole = Qt::UserRole + 3
  };

  AllowedCollisionMatrixModel(QObject *parent = nullptr);
  AllowedCollisionMatrixModel(const AllowedCollisionMatrixModel &other);
  AllowedCollisionMatrixModel &operator=(const AllowedCollisionMatrixModel &other);
  ~AllowedCollisionMatrixModel() override = default;

  Q_INVOKABLE void setEnvironment(tesseract_environment::Environment::Ptr env);
  Q_INVOKABLE void add(const QString& link_name1, const QString& link_name2, const QString& reason);
  Q_INVOKABLE void clear();

  QHash<int, QByteArray> roleNames() const override;

private:
  tesseract_environment::Environment::Ptr env_ {nullptr};
};
}
Q_DECLARE_METATYPE(tesseract_ignition::AllowedCollisionMatrixModel)

#endif // TESSERACT_IGNITION_ALLOWED_COLLISION_MATRIX_MODEL_H
