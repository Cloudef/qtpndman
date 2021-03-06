#include "qtpndman.h"
#include <QDebug>
#include <QCoreApplication>

int main(int argc, char** argv)
{
  QCoreApplication application(argc, argv);
  
  pndman_set_verbose(PNDMAN_LEVEL_CRAP);

  QPndman::Context* context = new QPndman::Context(&application);
  
  QPndman::Device* device = new QPndman::Device(context, "/tmp");
  QPndman::Repository* repo = new QPndman::Repository(context, "http://repo.openpandora.org/client/masterlist");
  
  repo->loadFrom(device);
  QPndman::SyncHandle* synchandle = repo->sync();
  while(context->processDownload()) synchandle->update();
  device->saveRepositories();
  
  QList<QPndman::Package*> packages = repo->getPackages();
  
  if(packages.size() == 0)
  {
    qDebug() << "ERROR: No packages to install!";
    return 1;
  }
  
  qsrand(QDateTime::currentMSecsSinceEpoch());
  QPndman::Package* toInstall = packages.at(qrand() % packages.size());
  
  qDebug() << "Installing:" << toInstall->getTitle();
  QPndman::InstallHandle* handle = toInstall->install(device, QPndman::Enum::Menu);

  if(!handle)
  {
    qDebug() << "ERROR: Could not initiate install!";
    return 1;    
  }
  qDebug() << "Downloading...";
  int counter = 0;
  while(context->processDownload() > 0)
  {
    if(handle->getBytesToDownload() != 0)
    {
      int percentage = 100 * handle->getBytesDownloaded() / handle->getBytesToDownload();
      if(counter + 10 <= percentage)
      {
        counter += 10;
        qDebug() << percentage << "%";
      }
    }
    else
    {
      if(counter + 1024*100 <= handle->getBytesDownloaded())
      {
        counter += 1024*100;
        qDebug() << handle->getBytesDownloaded() / 1024 << "KiB";
      }
    }

  }

  device->saveRepositories();
  qDebug() << "Done";
  
  qDebug() << "Crawling";
  device->crawl();
  qDebug() << "Checking for removed packages";
  context->checkLocalPndmanRepository();
  qDebug() << "Checking for upgrades";
  context->checkUpgrades();

  QPndman::Repository* localRepo = new QPndman::LocalRepository(context);
  
  qDebug() << "Installed packages:";
  foreach(QPndman::Package* installed, localRepo->getPackages())
  {
    qDebug() << installed->getTitle();
  }
  
  device->saveRepositories();
  return 0;
}
  
  
