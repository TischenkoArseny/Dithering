#pragma once

#include "idither.h"
#include "RgbColor.h"
#include <QImage>
#include "palette.h"

class SierraLiteDither : public IDither 
{
public:
	void execute(QImage &img, palette &plt) override;
};