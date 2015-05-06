/*
 * RAW Dirac demuxer
 * Copyright (c) 2007 Marco Gerards <marco@gnu.org>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation;
 * version 2 of the License.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "rawdec.h"

static int dirac_probe(AVProbeData *p)
{
    if (AV_RL32(p->buf) == MKTAG('B', 'B', 'C', 'D'))
        return AVPROBE_SCORE_MAX;
    else
        return 0;
}

FF_DEF_RAWVIDEO_DEMUXER(dirac, "raw Dirac", dirac_probe, NULL, CODEC_ID_DIRAC)
