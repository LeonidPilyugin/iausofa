#pragma once

/*
**  - - - - - - -
**   s o f a . h
**  - - - - - - -
**
**  Prototype function declarations for SOFA library.
**
**  This file is part of the International Astronomical Union's
**  SOFA (Standards Of Fundamental Astronomy) software collection.
**
**  This revision:   2018 December 5
**
**  SOFA release 2020-07-21
**
**  Copyright (C) 2020 IAU SOFA Board.  See notes at end.
*/

#include "sofam.h"
#include "math.h"

#ifdef IAUSOFA_EXPORTS
#define IAUSOFA_API __declspec(dllexport)
#else
#define IAUSOFA_API __declspec(dllimport)
#endif

/* Astronomy/Calendars */
extern "C" IAUSOFA_API int iauCal2jd(int iy, int im, int id, double* djm0, double* djm);
extern "C" IAUSOFA_API double iauEpb(double dj1, double dj2);
extern "C" IAUSOFA_API void iauEpb2jd(double epb, double* djm0, double* djm);
extern "C" IAUSOFA_API double iauEpj(double dj1, double dj2);
extern "C" IAUSOFA_API void iauEpj2jd(double epj, double* djm0, double* djm);
extern "C" IAUSOFA_API int iauJd2cal(double dj1, double dj2,
    int* iy, int* im, int* id, double* fd);
extern "C" IAUSOFA_API int iauJdcalf(int ndp, double dj1, double dj2, int iymdf[4]);

/* Astronomy/Astrometry */
extern "C" IAUSOFA_API void iauAb(double pnat[3], double v[3], double s, double bm1,
    double ppr[3]);
extern "C" IAUSOFA_API void iauApcg(double date1, double date2,
    double ebpv[2][3], double ehp[3],
    iauASTROM* astrom);
extern "C" IAUSOFA_API void iauApcg13(double date1, double date2, iauASTROM* astrom);
extern "C" IAUSOFA_API void iauApci(double date1, double date2,
    double ebpv[2][3], double ehp[3],
    double x, double y, double s,
    iauASTROM* astrom);
extern "C" IAUSOFA_API void iauApci13(double date1, double date2,
    iauASTROM* astrom, double* eo);
extern "C" IAUSOFA_API void iauApco(double date1, double date2,
    double ebpv[2][3], double ehp[3],
    double x, double y, double s, double theta,
    double elong, double phi, double hm,
    double xp, double yp, double sp,
    double refa, double refb,
    iauASTROM* astrom);
extern "C" IAUSOFA_API int iauApco13(double utc1, double utc2, double dut1,
    double elong, double phi, double hm, double xp, double yp,
    double phpa, double tc, double rh, double wl,
    iauASTROM* astrom, double* eo);
extern "C" IAUSOFA_API void iauApcs(double date1, double date2, double pv[2][3],
    double ebpv[2][3], double ehp[3],
    iauASTROM* astrom);
extern "C" IAUSOFA_API void iauApcs13(double date1, double date2, double pv[2][3],
    iauASTROM* astrom);
extern "C" IAUSOFA_API void iauAper(double theta, iauASTROM* astrom);
extern "C" IAUSOFA_API void iauAper13(double ut11, double ut12, iauASTROM* astrom);
extern "C" IAUSOFA_API void iauApio(double sp, double theta,
    double elong, double phi, double hm, double xp, double yp,
    double refa, double refb,
    iauASTROM* astrom);
extern "C" IAUSOFA_API int iauApio13(double utc1, double utc2, double dut1,
    double elong, double phi, double hm, double xp, double yp,
    double phpa, double tc, double rh, double wl,
    iauASTROM* astrom);
extern "C" IAUSOFA_API void iauAtci13(double rc, double dc,
    double pr, double pd, double px, double rv,
    double date1, double date2,
    double* ri, double* di, double* eo);
extern "C" IAUSOFA_API void iauAtciq(double rc, double dc, double pr, double pd,
    double px, double rv, iauASTROM* astrom,
    double* ri, double* di);
extern "C" IAUSOFA_API void iauAtciqn(double rc, double dc, double pr, double pd,
    double px, double rv, iauASTROM* astrom,
    int n, iauLDBODY b[], double* ri, double* di);
extern "C" IAUSOFA_API void iauAtciqz(double rc, double dc, iauASTROM* astrom,
    double* ri, double* di);
extern "C" IAUSOFA_API int iauAtco13(double rc, double dc,
    double pr, double pd, double px, double rv,
    double utc1, double utc2, double dut1,
    double elong, double phi, double hm, double xp, double yp,
    double phpa, double tc, double rh, double wl,
    double* aob, double* zob, double* hob,
    double* dob, double* rob, double* eo);
extern "C" IAUSOFA_API void iauAtic13(double ri, double di,
    double date1, double date2,
    double* rc, double* dc, double* eo);
extern "C" IAUSOFA_API void iauAticq(double ri, double di, iauASTROM* astrom,
    double* rc, double* dc);
extern "C" IAUSOFA_API void iauAticqn(double ri, double di, iauASTROM* astrom,
    int n, iauLDBODY b[], double* rc, double* dc);
extern "C" IAUSOFA_API int iauAtio13(double ri, double di,
    double utc1, double utc2, double dut1,
    double elong, double phi, double hm, double xp, double yp,
    double phpa, double tc, double rh, double wl,
    double* aob, double* zob, double* hob,
    double* dob, double* rob);
extern "C" IAUSOFA_API void iauAtioq(double ri, double di, iauASTROM* astrom,
    double* aob, double* zob,
    double* hob, double* dob, double* rob);
extern "C" IAUSOFA_API int iauAtoc13(const char* type, double ob1, double ob2,
    double utc1, double utc2, double dut1,
    double elong, double phi, double hm, double xp, double yp,
    double phpa, double tc, double rh, double wl,
    double* rc, double* dc);
extern "C" IAUSOFA_API int iauAtoi13(const char* type, double ob1, double ob2,
    double utc1, double utc2, double dut1,
    double elong, double phi, double hm, double xp, double yp,
    double phpa, double tc, double rh, double wl,
    double* ri, double* di);
extern "C" IAUSOFA_API void iauAtoiq(const char* type,
    double ob1, double ob2, iauASTROM* astrom,
    double* ri, double* di);
extern "C" IAUSOFA_API void iauLd(double bm, double p[3], double q[3], double e[3],
    double em, double dlim, double p1[3]);
extern "C" IAUSOFA_API void iauLdn(int n, iauLDBODY b[], double ob[3], double sc[3],
    double sn[3]);
extern "C" IAUSOFA_API void iauLdsun(double p[3], double e[3], double em, double p1[3]);
extern "C" IAUSOFA_API void iauPmpx(double rc, double dc, double pr, double pd,
    double px, double rv, double pmt, double pob[3],
    double pco[3]);
extern "C" IAUSOFA_API int iauPmsafe(double ra1, double dec1, double pmr1, double pmd1,
    double px1, double rv1,
    double ep1a, double ep1b, double ep2a, double ep2b,
    double* ra2, double* dec2, double* pmr2, double* pmd2,
    double* px2, double* rv2);
extern "C" IAUSOFA_API void iauPvtob(double elong, double phi, double height, double xp,
    double yp, double sp, double theta, double pv[2][3]);
extern "C" IAUSOFA_API void iauRefco(double phpa, double tc, double rh, double wl,
    double* refa, double* refb);

/* Astronomy/Ephemerides */
extern "C" IAUSOFA_API int iauEpv00(double date1, double date2,
    double pvh[2][3], double pvb[2][3]);
extern "C" IAUSOFA_API int iauPlan94(double date1, double date2, int np, double pv[2][3]);

/* Astronomy/FundamentalArgs */
extern "C" IAUSOFA_API double iauFad03(double t);
extern "C" IAUSOFA_API double iauFae03(double t);
extern "C" IAUSOFA_API double iauFaf03(double t);
extern "C" IAUSOFA_API double iauFaju03(double t);
extern "C" IAUSOFA_API double iauFal03(double t);
extern "C" IAUSOFA_API double iauFalp03(double t);
extern "C" IAUSOFA_API double iauFama03(double t);
extern "C" IAUSOFA_API double iauFame03(double t);
extern "C" IAUSOFA_API double iauFane03(double t);
extern "C" IAUSOFA_API double iauFaom03(double t);
extern "C" IAUSOFA_API double iauFapa03(double t);
extern "C" IAUSOFA_API double iauFasa03(double t);
extern "C" IAUSOFA_API double iauFaur03(double t);
extern "C" IAUSOFA_API double iauFave03(double t);

/* Astronomy/PrecNutPolar */
extern "C" IAUSOFA_API void iauBi00(double* dpsibi, double* depsbi, double* dra);
extern "C" IAUSOFA_API void iauBp00(double date1, double date2,
    double rb[3][3], double rp[3][3], double rbp[3][3]);
extern "C" IAUSOFA_API void iauBp06(double date1, double date2,
    double rb[3][3], double rp[3][3], double rbp[3][3]);
extern "C" IAUSOFA_API void iauBpn2xy(double rbpn[3][3], double* x, double* y);
extern "C" IAUSOFA_API void iauC2i00a(double date1, double date2, double rc2i[3][3]);
extern "C" IAUSOFA_API void iauC2i00b(double date1, double date2, double rc2i[3][3]);
extern "C" IAUSOFA_API void iauC2i06a(double date1, double date2, double rc2i[3][3]);
extern "C" IAUSOFA_API void iauC2ibpn(double date1, double date2, double rbpn[3][3],
    double rc2i[3][3]);
extern "C" IAUSOFA_API void iauC2ixy(double date1, double date2, double x, double y,
    double rc2i[3][3]);
extern "C" IAUSOFA_API void iauC2ixys(double x, double y, double s, double rc2i[3][3]);
extern "C" IAUSOFA_API void iauC2t00a(double tta, double ttb, double uta, double utb,
    double xp, double yp, double rc2t[3][3]);
extern "C" IAUSOFA_API void iauC2t00b(double tta, double ttb, double uta, double utb,
    double xp, double yp, double rc2t[3][3]);
extern "C" IAUSOFA_API void iauC2t06a(double tta, double ttb, double uta, double utb,
    double xp, double yp, double rc2t[3][3]);
extern "C" IAUSOFA_API void iauC2tcio(double rc2i[3][3], double era, double rpom[3][3],
    double rc2t[3][3]);
extern "C" IAUSOFA_API void iauC2teqx(double rbpn[3][3], double gst, double rpom[3][3],
    double rc2t[3][3]);
extern "C" IAUSOFA_API void iauC2tpe(double tta, double ttb, double uta, double utb,
    double dpsi, double deps, double xp, double yp,
    double rc2t[3][3]);
extern "C" IAUSOFA_API void iauC2txy(double tta, double ttb, double uta, double utb,
    double x, double y, double xp, double yp,
    double rc2t[3][3]);
extern "C" IAUSOFA_API double iauEo06a(double date1, double date2);
extern "C" IAUSOFA_API double iauEors(double rnpb[3][3], double s);
extern "C" IAUSOFA_API void iauFw2m(double gamb, double phib, double psi, double eps,
    double r[3][3]);
extern "C" IAUSOFA_API void iauFw2xy(double gamb, double phib, double psi, double eps,
    double* x, double* y);
extern "C" IAUSOFA_API void iauLtp(double epj, double rp[3][3]);
extern "C" IAUSOFA_API void iauLtpb(double epj, double rpb[3][3]);
extern "C" IAUSOFA_API void iauLtpecl(double epj, double vec[3]);
extern "C" IAUSOFA_API void iauLtpequ(double epj, double veq[3]);
extern "C" IAUSOFA_API void iauNum00a(double date1, double date2, double rmatn[3][3]);
extern "C" IAUSOFA_API void iauNum00b(double date1, double date2, double rmatn[3][3]);
extern "C" IAUSOFA_API void iauNum06a(double date1, double date2, double rmatn[3][3]);
extern "C" IAUSOFA_API void iauNumat(double epsa, double dpsi, double deps, double rmatn[3][3]);
extern "C" IAUSOFA_API void iauNut00a(double date1, double date2, double* dpsi, double* deps);
extern "C" IAUSOFA_API void iauNut00b(double date1, double date2, double* dpsi, double* deps);
extern "C" IAUSOFA_API void iauNut06a(double date1, double date2, double* dpsi, double* deps);
extern "C" IAUSOFA_API void iauNut80(double date1, double date2, double* dpsi, double* deps);
extern "C" IAUSOFA_API void iauNutm80(double date1, double date2, double rmatn[3][3]);
extern "C" IAUSOFA_API double iauObl06(double date1, double date2);
extern "C" IAUSOFA_API double iauObl80(double date1, double date2);
extern "C" IAUSOFA_API void iauP06e(double date1, double date2,
    double* eps0, double* psia, double* oma, double* bpa,
    double* bqa, double* pia, double* bpia,
    double* epsa, double* chia, double* za, double* zetaa,
    double* thetaa, double* pa,
    double* gam, double* phi, double* psi);
extern "C" IAUSOFA_API void iauPb06(double date1, double date2,
    double* bzeta, double* bz, double* btheta);
extern "C" IAUSOFA_API void iauPfw06(double date1, double date2,
    double* gamb, double* phib, double* psib, double* epsa);
extern "C" IAUSOFA_API void iauPmat00(double date1, double date2, double rbp[3][3]);
extern "C" IAUSOFA_API void iauPmat06(double date1, double date2, double rbp[3][3]);
extern "C" IAUSOFA_API void iauPmat76(double date1, double date2, double rmatp[3][3]);
extern "C" IAUSOFA_API void iauPn00(double date1, double date2, double dpsi, double deps,
    double* epsa,
    double rb[3][3], double rp[3][3], double rbp[3][3],
    double rn[3][3], double rbpn[3][3]);
extern "C" IAUSOFA_API void iauPn00a(double date1, double date2,
    double* dpsi, double* deps, double* epsa,
    double rb[3][3], double rp[3][3], double rbp[3][3],
    double rn[3][3], double rbpn[3][3]);
extern "C" IAUSOFA_API void iauPn00b(double date1, double date2,
    double* dpsi, double* deps, double* epsa,
    double rb[3][3], double rp[3][3], double rbp[3][3],
    double rn[3][3], double rbpn[3][3]);
extern "C" IAUSOFA_API void iauPn06(double date1, double date2, double dpsi, double deps,
    double* epsa,
    double rb[3][3], double rp[3][3], double rbp[3][3],
    double rn[3][3], double rbpn[3][3]);
extern "C" IAUSOFA_API void iauPn06a(double date1, double date2,
    double* dpsi, double* deps, double* epsa,
    double rb[3][3], double rp[3][3], double rbp[3][3],
    double rn[3][3], double rbpn[3][3]);
extern "C" IAUSOFA_API void iauPnm00a(double date1, double date2, double rbpn[3][3]);
extern "C" IAUSOFA_API void iauPnm00b(double date1, double date2, double rbpn[3][3]);
extern "C" IAUSOFA_API void iauPnm06a(double date1, double date2, double rnpb[3][3]);
extern "C" IAUSOFA_API void iauPnm80(double date1, double date2, double rmatpn[3][3]);
extern "C" IAUSOFA_API void iauPom00(double xp, double yp, double sp, double rpom[3][3]);
extern "C" IAUSOFA_API void iauPr00(double date1, double date2,
    double* dpsipr, double* depspr);
extern "C" IAUSOFA_API void iauPrec76(double date01, double date02,
    double date11, double date12,
    double* zeta, double* z, double* theta);
extern "C" IAUSOFA_API double iauS00(double date1, double date2, double x, double y);
extern "C" IAUSOFA_API double iauS00a(double date1, double date2);
extern "C" IAUSOFA_API double iauS00b(double date1, double date2);
extern "C" IAUSOFA_API double iauS06(double date1, double date2, double x, double y);
extern "C" IAUSOFA_API double iauS06a(double date1, double date2);
extern "C" IAUSOFA_API double iauSp00(double date1, double date2);
extern "C" IAUSOFA_API void iauXy06(double date1, double date2, double* x, double* y);
extern "C" IAUSOFA_API void iauXys00a(double date1, double date2,
    double* x, double* y, double* s);
extern "C" IAUSOFA_API void iauXys00b(double date1, double date2,
    double* x, double* y, double* s);
extern "C" IAUSOFA_API void iauXys06a(double date1, double date2,
    double* x, double* y, double* s);

/* Astronomy/RotationAndTime */
extern "C" IAUSOFA_API double iauEe00(double date1, double date2, double epsa, double dpsi);
extern "C" IAUSOFA_API double iauEe00a(double date1, double date2);
extern "C" IAUSOFA_API double iauEe00b(double date1, double date2);
extern "C" IAUSOFA_API double iauEe06a(double date1, double date2);
extern "C" IAUSOFA_API double iauEect00(double date1, double date2);
extern "C" IAUSOFA_API double iauEqeq94(double date1, double date2);
extern "C" IAUSOFA_API double iauEra00(double dj1, double dj2);
extern "C" IAUSOFA_API double iauGmst00(double uta, double utb, double tta, double ttb);
extern "C" IAUSOFA_API double iauGmst06(double uta, double utb, double tta, double ttb);
extern "C" IAUSOFA_API double iauGmst82(double dj1, double dj2);
extern "C" IAUSOFA_API double iauGst00a(double uta, double utb, double tta, double ttb);
extern "C" IAUSOFA_API double iauGst00b(double uta, double utb);
extern "C" IAUSOFA_API double iauGst06(double uta, double utb, double tta, double ttb,
    double rnpb[3][3]);
extern "C" IAUSOFA_API double iauGst06a(double uta, double utb, double tta, double ttb);
extern "C" IAUSOFA_API double iauGst94(double uta, double utb);

/* Astronomy/SpaceMotion */
extern "C" IAUSOFA_API int iauPvstar(double pv[2][3], double* ra, double* dec,
    double* pmr, double* pmd, double* px, double* rv);
extern "C" IAUSOFA_API int iauStarpv(double ra, double dec,
    double pmr, double pmd, double px, double rv,
    double pv[2][3]);

/* Astronomy/StarCatalogs */

extern "C" IAUSOFA_API void iauFk425(double r1950, double d1950,
    double dr1950, double dd1950,
    double p1950, double v1950,
    double* r2000, double* d2000,
    double* dr2000, double* dd2000,
    double* p2000, double* v2000);
extern "C" IAUSOFA_API void iauFk45z(double r1950, double d1950, double bepoch,
    double* r2000, double* d2000);
extern "C" IAUSOFA_API void iauFk524(double r2000, double d2000,
    double dr2000, double dd2000,
    double p2000, double v2000,
    double* r1950, double* d1950,
    double* dr1950, double* dd1950,
    double* p1950, double* v1950);
extern "C" IAUSOFA_API void iauFk52h(double r5, double d5,
    double dr5, double dd5, double px5, double rv5,
    double* rh, double* dh,
    double* drh, double* ddh, double* pxh, double* rvh);
extern "C" IAUSOFA_API void iauFk54z(double r2000, double d2000, double bepoch,
    double* r1950, double* d1950,
    double* dr1950, double* dd1950);
extern "C" IAUSOFA_API void iauFk5hip(double r5h[3][3], double s5h[3]);
extern "C" IAUSOFA_API void iauFk5hz(double r5, double d5, double date1, double date2,
    double* rh, double* dh);
extern "C" IAUSOFA_API void iauH2fk5(double rh, double dh,
    double drh, double ddh, double pxh, double rvh,
    double* r5, double* d5,
    double* dr5, double* dd5, double* px5, double* rv5);
extern "C" IAUSOFA_API void iauHfk5z(double rh, double dh, double date1, double date2,
    double* r5, double* d5, double* dr5, double* dd5);
extern "C" IAUSOFA_API int iauStarpm(double ra1, double dec1,
    double pmr1, double pmd1, double px1, double rv1,
    double ep1a, double ep1b, double ep2a, double ep2b,
    double* ra2, double* dec2,
    double* pmr2, double* pmd2, double* px2, double* rv2);

/* Astronomy/EclipticCoordinates */
extern "C" IAUSOFA_API void iauEceq06(double date1, double date2, double dl, double db,
    double* dr, double* dd);
extern "C" IAUSOFA_API void iauEcm06(double date1, double date2, double rm[3][3]);
extern "C" IAUSOFA_API void iauEqec06(double date1, double date2, double dr, double dd,
    double* dl, double* db);
extern "C" IAUSOFA_API void iauLteceq(double epj, double dl, double db, double* dr, double* dd);
extern "C" IAUSOFA_API void iauLtecm(double epj, double rm[3][3]);
extern "C" IAUSOFA_API void iauLteqec(double epj, double dr, double dd, double* dl, double* db);

/* Astronomy/GalacticCoordinates */
extern "C" IAUSOFA_API void iauG2icrs(double dl, double db, double* dr, double* dd);
extern "C" IAUSOFA_API void iauIcrs2g(double dr, double dd, double* dl, double* db);

/* Astronomy/GeodeticGeocentric */
extern "C" IAUSOFA_API int iauEform(int n, double* a, double* f);
extern "C" IAUSOFA_API int iauGc2gd(int n, double xyz[3],
    double* elong, double* phi, double* height);
extern "C" IAUSOFA_API int iauGc2gde(double a, double f, double xyz[3],
    double* elong, double* phi, double* height);
extern "C" IAUSOFA_API int iauGd2gc(int n, double elong, double phi, double height,
    double xyz[3]);
extern "C" IAUSOFA_API int iauGd2gce(double a, double f,
    double elong, double phi, double height, double xyz[3]);

/* Astronomy/Timescales */
extern "C" IAUSOFA_API int iauD2dtf(const char* scale, int ndp, double d1, double d2,
    int* iy, int* im, int* id, int ihmsf[4]);
extern "C" IAUSOFA_API int iauDat(int iy, int im, int id, double fd, double* deltat);
extern "C" IAUSOFA_API double iauDtdb(double date1, double date2,
    double ut, double elong, double u, double v);
extern "C" IAUSOFA_API int iauDtf2d(const char* scale, int iy, int im, int id,
    int ihr, int imn, double sec, double* d1, double* d2);
extern "C" IAUSOFA_API int iauTaitt(double tai1, double tai2, double* tt1, double* tt2);
extern "C" IAUSOFA_API int iauTaiut1(double tai1, double tai2, double dta,
    double* ut11, double* ut12);
extern "C" IAUSOFA_API int iauTaiutc(double tai1, double tai2, double* utc1, double* utc2);
extern "C" IAUSOFA_API int iauTcbtdb(double tcb1, double tcb2, double* tdb1, double* tdb2);
extern "C" IAUSOFA_API int iauTcgtt(double tcg1, double tcg2, double* tt1, double* tt2);
extern "C" IAUSOFA_API int iauTdbtcb(double tdb1, double tdb2, double* tcb1, double* tcb2);
extern "C" IAUSOFA_API int iauTdbtt(double tdb1, double tdb2, double dtr,
    double* tt1, double* tt2);
extern "C" IAUSOFA_API int iauTttai(double tt1, double tt2, double* tai1, double* tai2);
extern "C" IAUSOFA_API int iauTttcg(double tt1, double tt2, double* tcg1, double* tcg2);
extern "C" IAUSOFA_API int iauTttdb(double tt1, double tt2, double dtr,
    double* tdb1, double* tdb2);
extern "C" IAUSOFA_API int iauTtut1(double tt1, double tt2, double dt,
    double* ut11, double* ut12);
extern "C" IAUSOFA_API int iauUt1tai(double ut11, double ut12, double dta,
    double* tai1, double* tai2);
extern "C" IAUSOFA_API int iauUt1tt(double ut11, double ut12, double dt,
    double* tt1, double* tt2);
extern "C" IAUSOFA_API int iauUt1utc(double ut11, double ut12, double dut1,
    double* utc1, double* utc2);
extern "C" IAUSOFA_API int iauUtctai(double utc1, double utc2, double* tai1, double* tai2);
extern "C" IAUSOFA_API int iauUtcut1(double utc1, double utc2, double dut1,
    double* ut11, double* ut12);

/* Astronomy/HorizonEquatorial */
extern "C" IAUSOFA_API void iauAe2hd(double az, double el, double phi,
    double* ha, double* dec);
extern "C" IAUSOFA_API void iauHd2ae(double ha, double dec, double phi,
    double* az, double* el);
extern "C" IAUSOFA_API double iauHd2pa(double ha, double dec, double phi);

/* Astronomy/Gnomonic */
extern "C" IAUSOFA_API int iauTpors(double xi, double eta, double a, double b,
    double* a01, double* b01, double* a02, double* b02);
extern "C" IAUSOFA_API int iauTporv(double xi, double eta, double v[3],
    double v01[3], double v02[3]);
extern "C" IAUSOFA_API void iauTpsts(double xi, double eta, double a0, double b0,
    double* a, double* b);
extern "C" IAUSOFA_API void iauTpstv(double xi, double eta, double v0[3], double v[3]);
extern "C" IAUSOFA_API int iauTpxes(double a, double b, double a0, double b0,
    double* xi, double* eta);
extern "C" IAUSOFA_API int iauTpxev(double v[3], double v0[3], double* xi, double* eta);

/* VectorMatrix/AngleOps */
extern "C" IAUSOFA_API void iauA2af(int ndp, double angle, char* sign, int idmsf[4]);
extern "C" IAUSOFA_API void iauA2tf(int ndp, double angle, char* sign, int ihmsf[4]);
extern "C" IAUSOFA_API int iauAf2a(char s, int ideg, int iamin, double asec, double* rad);
extern "C" IAUSOFA_API double iauAnp(double a);
extern "C" IAUSOFA_API double iauAnpm(double a);
extern "C" IAUSOFA_API void iauD2tf(int ndp, double days, char* sign, int ihmsf[4]);
extern "C" IAUSOFA_API int iauTf2a(char s, int ihour, int imin, double sec, double* rad);
extern "C" IAUSOFA_API int iauTf2d(char s, int ihour, int imin, double sec, double* days);

/* VectorMatrix/BuildRotations */
extern "C" IAUSOFA_API void iauRx(double phi, double r[3][3]);
extern "C" IAUSOFA_API void iauRy(double theta, double r[3][3]);
extern "C" IAUSOFA_API void iauRz(double psi, double r[3][3]);

/* VectorMatrix/CopyExtendExtract */
extern "C" IAUSOFA_API void iauCp(double p[3], double c[3]);
extern "C" IAUSOFA_API void iauCpv(double pv[2][3], double c[2][3]);
extern "C" IAUSOFA_API void iauCr(double r[3][3], double c[3][3]);
extern "C" IAUSOFA_API void iauP2pv(double p[3], double pv[2][3]);
extern "C" IAUSOFA_API void iauPv2p(double pv[2][3], double p[3]);

/* VectorMatrix/Initialization */
extern "C" IAUSOFA_API void iauIr(double r[3][3]);
extern "C" IAUSOFA_API void iauZp(double p[3]);
extern "C" IAUSOFA_API void iauZpv(double pv[2][3]);
extern "C" IAUSOFA_API void iauZr(double r[3][3]);

/* VectorMatrix/MatrixOps */
extern "C" IAUSOFA_API void iauRxr(double a[3][3], double b[3][3], double atb[3][3]);
extern "C" IAUSOFA_API void iauTr(double r[3][3], double rt[3][3]);

/* VectorMatrix/MatrixVectorProducts */
extern "C" IAUSOFA_API void iauRxp(double r[3][3], double p[3], double rp[3]);
extern "C" IAUSOFA_API void iauRxpv(double r[3][3], double pv[2][3], double rpv[2][3]);
extern "C" IAUSOFA_API void iauTrxp(double r[3][3], double p[3], double trp[3]);
extern "C" IAUSOFA_API void iauTrxpv(double r[3][3], double pv[2][3], double trpv[2][3]);

/* VectorMatrix/RotationVectors */
extern "C" IAUSOFA_API void iauRm2v(double r[3][3], double w[3]);
extern "C" IAUSOFA_API void iauRv2m(double w[3], double r[3][3]);

/* VectorMatrix/SeparationAndAngle */
extern "C" IAUSOFA_API double iauPap(double a[3], double b[3]);
extern "C" IAUSOFA_API double iauPas(double al, double ap, double bl, double bp);
extern "C" IAUSOFA_API double iauSepp(double a[3], double b[3]);
extern "C" IAUSOFA_API double iauSeps(double al, double ap, double bl, double bp);

/* VectorMatrix/SphericalCartesian */
extern "C" IAUSOFA_API void iauC2s(double p[3], double* theta, double* phi);
extern "C" IAUSOFA_API void iauP2s(double p[3], double* theta, double* phi, double* r);
extern "C" IAUSOFA_API void iauPv2s(double pv[2][3],
    double* theta, double* phi, double* r,
    double* td, double* pd, double* rd);
extern "C" IAUSOFA_API void iauS2c(double theta, double phi, double c[3]);
extern "C" IAUSOFA_API void iauS2p(double theta, double phi, double r, double p[3]);
extern "C" IAUSOFA_API void iauS2pv(double theta, double phi, double r,
    double td, double pd, double rd,
    double pv[2][3]);

/* VectorMatrix/VectorOps */
extern "C" IAUSOFA_API double iauPdp(double a[3], double b[3]);
extern "C" IAUSOFA_API double iauPm(double p[3]);
extern "C" IAUSOFA_API void iauPmp(double a[3], double b[3], double amb[3]);
extern "C" IAUSOFA_API void iauPn(double p[3], double* r, double u[3]);
extern "C" IAUSOFA_API void iauPpp(double a[3], double b[3], double apb[3]);
extern "C" IAUSOFA_API void iauPpsp(double a[3], double s, double b[3], double apsb[3]);
extern "C" IAUSOFA_API void iauPvdpv(double a[2][3], double b[2][3], double adb[2]);
extern "C" IAUSOFA_API void iauPvm(double pv[2][3], double* r, double* s);
extern "C" IAUSOFA_API void iauPvmpv(double a[2][3], double b[2][3], double amb[2][3]);
extern "C" IAUSOFA_API void iauPvppv(double a[2][3], double b[2][3], double apb[2][3]);
extern "C" IAUSOFA_API void iauPvu(double dt, double pv[2][3], double upv[2][3]);
extern "C" IAUSOFA_API void iauPvup(double dt, double pv[2][3], double p[3]);
extern "C" IAUSOFA_API void iauPvxpv(double a[2][3], double b[2][3], double axb[2][3]);
extern "C" IAUSOFA_API void iauPxp(double a[3], double b[3], double axb[3]);
extern "C" IAUSOFA_API void iauS2xpv(double s1, double s2, double pv[2][3], double spv[2][3]);
extern "C" IAUSOFA_API void iauSxp(double s, double p[3], double sp[3]);
extern "C" IAUSOFA_API void iauSxpv(double s, double pv[2][3], double spv[2][3]);



/*----------------------------------------------------------------------
**
**  Copyright (C) 2020
**  Standards Of Fundamental Astronomy Board
**  of the International Astronomical Union.
**
**  =====================
**  SOFA Software License
**  =====================
**
**  NOTICE TO USER:
**
**  BY USING THIS SOFTWARE YOU ACCEPT THE FOLLOWING SIX TERMS AND
**  CONDITIONS WHICH APPLY TO ITS USE.
**
**  1. The Software is owned by the IAU SOFA Board ("SOFA").
**
**  2. Permission is granted to anyone to use the SOFA software for any
**     purpose, including commercial applications, free of charge and
**     without payment of royalties, subject to the conditions and
**     restrictions listed below.
**
**  3. You (the user) may copy and distribute SOFA source code to others,
**     and use and adapt its code and algorithms in your own software,
**     on a world-wide, royalty-free basis.  That portion of your
**     distribution that does not consist of intact and unchanged copies
**     of SOFA source code files is a "derived work" that must comply
**     with the following requirements:
**
**     a) Your work shall be marked or carry a statement that it
**        (i) uses routines and computations derived by you from
**        software provided by SOFA under license to you; and
**        (ii) does not itself constitute software provided by and/or
**        endorsed by SOFA.
**
**     b) The source code of your derived work must contain descriptions
**        of how the derived work is based upon, contains and/or differs
**        from the original SOFA software.
**
**     c) The names of all routines in your derived work shall not
**        include the prefix "iau" or "sofa" or trivial modifications
**        thereof such as changes of case.
**
**     d) The origin of the SOFA components of your derived work must
**        not be misrepresented;  you must not claim that you wrote the
**        original software, nor file a patent application for SOFA
**        software or algorithms embedded in the SOFA software.
**
**     e) These requirements must be reproduced intact in any source
**        distribution and shall apply to anyone to whom you have
**        granted a further right to modify the source code of your
**        derived work.
**
**     Note that, as originally distributed, the SOFA software is
**     intended to be a definitive implementation of the IAU standards,
**     and consequently third-party modifications are discouraged.  All
**     variations, no matter how minor, must be explicitly marked as
**     such, as explained above.
**
**  4. You shall not cause the SOFA software to be brought into
**     disrepute, either by misuse, or use for inappropriate tasks, or
**     by inappropriate modification.
**
**  5. The SOFA software is provided "as is" and SOFA makes no warranty
**     as to its use or performance.   SOFA does not and cannot warrant
**     the performance or results which the user may obtain by using the
**     SOFA software.  SOFA makes no warranties, express or implied, as
**     to non-infringement of third party rights, merchantability, or
**     fitness for any particular purpose.  In no event will SOFA be
**     liable to the user for any consequential, incidental, or special
**     damages, including any lost profits or lost savings, even if a
**     SOFA representative has been advised of such damages, or for any
**     claim by any third party.
**
**  6. The provision of any version of the SOFA software under the terms
**     and conditions specified herein does not imply that future
**     versions will also be made available under the same terms and
**     conditions.
*
**  In any published work or commercial product which uses the SOFA
**  software directly, acknowledgement (see www.iausofa.org) is
**  appreciated.
**
**  Correspondence concerning SOFA software should be addressed as
**  follows:
**
**      By email:  sofa@ukho.gov.uk
**      By post:   IAU SOFA Center
**                 HM Nautical Almanac Office
**                 UK Hydrographic Office
**                 Admiralty Way, Taunton
**                 Somerset, TA1 2DN
**                 United Kingdom
**
**--------------------------------------------------------------------*/
