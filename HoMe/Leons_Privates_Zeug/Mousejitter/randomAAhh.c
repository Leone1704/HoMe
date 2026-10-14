#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/* Matrikelnummer in einen String schreiben */
int matrikelnr(char *nr, int maxlen)
{
	if (maxlen >= 8)
	{
		strcpy(nr, "3451948");
		return 0;
	}
	return -1;
}
/* Eingabewert mit Suffix (n, u, m, K, M, G, T) in Double umwandeln */
double suffix(const char *input)
{
	double value;
	char suffix_char = 0;

	if (sscanf(input, " %lf %c", &value, &suffix_char) == 2) {
		switch (suffix_char) {
			case 'n': value *= 1e-9; break;
			case 'u': value *= 1e-6; break;
			case 'm': value *= 1e-3; break;
			case 'K': value *= 1e3;  break;
			case 'M': value *= 1e6;  break;
			case 'G': value *= 1e9;  break;
			case 'T': value *= 1e12; break;
			default: return -1;
		}
	} else {
		if (sscanf(input, " %lf", &value) != 1)
			return -1;
	}

	return value;
}
/* E-Reihe einlesen und validieren */
unsigned read_eseries(void)
{
	const unsigned valid[] = {3, 6, 12, 24, 48, 96, 192};
	const int valid_count = sizeof(valid) / sizeof(valid[0]);
	char buf[100];

	while (1) {
		printf("E-Reihe (3,6,12,24,48,96,192): ");
		fgets(buf, sizeof(buf), stdin);

		double v = suffix(buf);
		if (v < 0) continue;

		for (int i = 0; i < valid_count; i++) {
			if (fabs(v - valid[i]) < 0.1)  /* Floating-point Vergleich korrigieren */
				return (unsigned)v;
		}

		printf("Ungültige Eingabe.\n");
	}
}
/* Spannungsteilerverhältnis einlesen und validieren (0..1) */
double read_ratio(void)
{
	char buf[100];

	while (1) {
		printf("Spannungsteilerverhältnis (0..1): ");
		fgets(buf, sizeof(buf), stdin);

		double v = suffix(buf);
		if (v >= 0 && v <= 1)
			return v;

		printf("Ungültige Eingabe.\n");
	}
}
/* R2 einlesen (optional mit Suffix) */
double read_r2(void)
{
	char buf[100];

	while (1) {
		printf("R2 optional angeben (optional, mit n/u/m/K/M/G/T): ");
		fgets(buf, sizeof(buf), stdin);

		double v = suffix(buf);
		if (v >= 0)
			return v;

		printf("Ungültige Eingabe.\n");
	}
}
/* E-Reihen als Arrays */
const unsigned int E3[] = {
	10, 22, 47
};

const unsigned int E6[] = {
	10, 15, 22, 33, 47, 68
};

const unsigned int E12[] = {
	10, 12, 15, 18, 22, 27, 33, 39, 47, 56,
	68, 82
};

const unsigned int E24[] = {
	10, 11, 12, 13, 15, 16, 18, 20, 22, 24,
	27, 30, 33, 36, 39, 43, 47, 51, 56, 62,
	68, 75, 82, 91
};

const unsigned int E48[] = {
	10, 11, 12, 13, 15, 16, 18, 20,
	22, 24, 27, 30, 33, 36, 39, 43,
	47, 51, 56, 62, 68, 75, 82, 91
};

const unsigned int E96[] = {
	10, 10, 11, 11, 12, 12, 13, 13,
	15, 15, 16, 16, 18, 18, 20, 20,
	22, 22, 24, 24, 27, 27, 30, 30,
	33, 33, 36, 36, 39, 39, 43, 43,
	47, 47, 51, 51, 56, 56, 62, 62,
	68, 68, 75, 75, 82, 82, 91, 91
};

const unsigned int E192[] = {
	10, 10, 10, 10, 11, 11, 12, 12,
	13, 13, 15, 15, 16, 16, 18, 18,
	20, 20, 22, 22, 24, 24, 27, 27,
	30, 30, 33, 33, 36, 36, 39, 39,
	43, 43, 47, 47, 51, 51, 56, 56,
	62, 62, 68, 68, 75, 75, 82, 82,
	91, 91, 100, 100, 110, 110, 120, 120,
	130, 130, 150, 150, 160, 160, 180, 180,
	200, 200, 220, 220, 240, 240, 270, 270,
	300, 300, 330, 330, 360, 360, 390, 390,
	430, 430, 470, 470, 510, 510, 560, 560,
	620, 620, 680, 680, 750, 750, 820, 820,
	910, 910, 1000, 1000, 1100, 1100, 1200, 1200,
	1300, 1300, 1500, 1500, 1600, 1600, 1800, 1800,
	2000, 2000, 2200, 2200, 2400, 2400, 2700, 2700,
	3000, 3000, 3300, 3300, 3600, 3600, 3900, 3900,
	4300, 4300, 4700, 4700, 5100, 5100, 5600, 5600,
	6200, 6200, 6800, 6800, 7500, 7500, 8200, 8200,
	9100, 9100, 10000, 10000, 11000, 11000, 12000, 12000,
	13000, 13000, 15000, 15000, 16000, 16000, 18000, 18000
};
/* Größe einer E-Reihe zurückgeben */
static unsigned int get_eseries_size(unsigned int eseries)
{
	switch (eseries) {
		case 3:   return sizeof(E3) / sizeof(E3[0]);
		case 6:   return sizeof(E6) / sizeof(E6[0]);
		case 12:  return sizeof(E12) / sizeof(E12[0]);
		case 24:  return sizeof(E24) / sizeof(E24[0]);
		case 48:  return sizeof(E48) / sizeof(E48[0]);
		case 96:  return sizeof(E96) / sizeof(E96[0]);
		case 192: return sizeof(E192) / sizeof(E192[0]);
		default:  return 0;
	}
}

/* n-ten Wert einer bestimmten E-Reihe zurückgeben */
unsigned int eseries_getval(unsigned int nth, unsigned int eseries)
{
	const unsigned int *table;
	switch (eseries) {
		case 3:   table = E3;   break;
		case 6:   table = E6;   break;
		case 12:  table = E12;  break;
		case 24:  table = E24;  break;
		case 48:  table = E48;  break;
		case 96:  table = E96;  break;
		case 192: table = E192; break;
		default:
			printf("Ungültige E-Reihe\n");
			return 0;
	}
	return table[nth];
}
/* Strukturtyp für Spannungsteiler */
typedef struct
{
	unsigned int rtop;
	unsigned int rbot;
	double error;
	int scale;
} rdiv_t;
/* Für gegebenes R2 den passenden R1 Wert ermitteln */
void calc_rtop(unsigned int rbot, double resratio, unsigned int eseries,
			   rdiv_t *rdiv_negerr, rdiv_t *rdiv_poserr)
{
	unsigned int size = get_eseries_size(eseries);

	/* Alle Werte der E-Reihe durchprobieren */
	for (unsigned int nth = 0; nth < size; nth++) {
		unsigned int rtop = eseries_getval(nth, eseries);

		/* Echtes Verhältnis ausrechnen: Uout/Uin = R2 / (R1 + R2) */
		double ratio = (double)rbot / (rtop + rbot);

		/* Abweichung vom idealen Verhältnis in Prozent */
		double error = (ratio - resratio) * 100.0;

		/* Besten negativen Fehler aktualisieren */
		if (error < 0 && fabs(error) < fabs(rdiv_negerr->error)) {
			rdiv_negerr->rtop = rtop;
			rdiv_negerr->rbot = rbot;
			rdiv_negerr->error = error;
		}

		/* Besten positiven Fehler aktualisieren */
		if (error > 0 && fabs(error) < fabs(rdiv_poserr->error)) {
			rdiv_poserr->rtop = rtop;
			rdiv_poserr->rbot = rbot;
			rdiv_poserr->error = error;
		}
	}
}
/* Spannungsteiler-Widerstände berechnen */
void calc_divs(double givenr2, double resratio, unsigned int eseries,
			   rdiv_t *rdiv_negerr, rdiv_t *rdiv_poserr)
{
	unsigned int count = get_eseries_size(eseries);

	if (count == 0) {
		printf("Ungültige E-Reihe\n");
		return;
	}

	/* Große Startwerte für sichere Überschreibung */
	rdiv_negerr->error = 1e9;
	rdiv_poserr->error = 1e9;

	/* Wenn kein R2 vorgegeben: alle Kombinationen durchprobieren */
	if (givenr2 == 0.0) {
		for (unsigned int i = 0; i < count; i++) {
			unsigned int r2 = eseries_getval(i, eseries);
			calc_rtop(r2, resratio, eseries, rdiv_negerr, rdiv_poserr);
		}
		return;
	}

	/* R2 vorgegeben: Skalierung auf korrekten Bereich */
	double r2_scaled = givenr2;
	int scale = 0;

	/* Alle E-Reihen skalieren auf 10-91 Bereich */
	while (r2_scaled >= 100.0) {
		r2_scaled /= 10.0;
		scale++;
	}
	while (r2_scaled < 10.0) {
		r2_scaled *= 10.0;
		scale--;
	}

	/* Passenden R2-Wert in E-Reihe finden */
	unsigned int r2_low = eseries_getval(0, eseries);
	unsigned int r2_high = eseries_getval(count - 1, eseries);

	for (unsigned int i = 0; i < count; i++) {
		unsigned int val = eseries_getval(i, eseries);
		if (val <= r2_scaled + 0.5) {  /* Mit Toleranz vergleichen */
			r2_low = val;
		}
		if (val >= r2_scaled - 0.5 && val > r2_low) {  /* Erste Schranke von oben */
			r2_high = val;
			break;
		}
	}

	/* Ermittelte Widerstandswerte testen */
	rdiv_t tmp_neg = *rdiv_negerr;
	rdiv_t tmp_pos = *rdiv_poserr;

	calc_rtop(r2_low, resratio, eseries, &tmp_neg, &tmp_pos);
	tmp_neg.scale = scale;
	tmp_pos.scale = scale;

	if (fabs(tmp_neg.error) < fabs(rdiv_negerr->error)) {
		*rdiv_negerr = tmp_neg;
	}
	if (fabs(tmp_pos.error) < fabs(rdiv_poserr->error)) {
		*rdiv_poserr = tmp_pos;
	}

	/* Nur testen wenn r2_high unterschiedlich ist */
	if (r2_high != r2_low) {
		tmp_neg = *rdiv_negerr;
		tmp_pos = *rdiv_poserr;

		calc_rtop(r2_high, resratio, eseries, &tmp_neg, &tmp_pos);
		tmp_neg.scale = scale;
		tmp_pos.scale = scale;

		if (fabs(tmp_neg.error) < fabs(rdiv_negerr->error)) {
			*rdiv_negerr = tmp_neg;
		}
		if (fabs(tmp_pos.error) < fabs(rdiv_poserr->error)) {
			*rdiv_poserr = tmp_pos;
		}
	}
}
/* Ergebnisse ausgeben */
void ausgabe(rdiv_t *negerr, rdiv_t *poserr)
{
	printf("\nErgebnis:\n");

	/* Wenn positiver Fehler praktisch null ist */
	if (fabs(poserr->error) < 1e-9) {
		printf("R1 = %.3g Ohm, R2 = %.3g Ohm (Fehler = %.3f%%)\n",
			poserr->rtop * pow(10, poserr->scale),
			poserr->rbot * pow(10, poserr->scale),
			poserr->error);
	}
	/* Wenn negativer Fehler praktisch null ist */
	else if (fabs(negerr->error) < 1e-9) {
		printf("R1 = %.3g Ohm, R2 = %.3g Ohm (Fehler = %.3f%%)\n",
			negerr->rtop * pow(10, negerr->scale),
			negerr->rbot * pow(10, negerr->scale),
			negerr->error);
	}
	/* Beide Fehler vorhanden */
	else {
		if (negerr->error < 1e9) {
			printf("Nächst kleineres Verhältnis:\n");
			printf("R1 = %.3g Ohm, R2 = %.3g Ohm (Fehler = %.3f%%)\n",
				negerr->rtop * pow(10, negerr->scale),
				negerr->rbot * pow(10, negerr->scale),
				negerr->error);
		} else {
			printf("Kein kleineres Verhältnis gefunden.\n");
		}

		if (poserr->error < 1e9) {
			printf("Nächst größeres Verhältnis:\n");
			printf("R1 = %.3g Ohm, R2 = %.3g Ohm (Fehler = %.3f%%)\n",
				poserr->rtop * pow(10, poserr->scale),
				poserr->rbot * pow(10, poserr->scale),
				poserr->error);
		} else {
			printf("Kein größeres Verhältnis gefunden.\n");
		}
	}
}

int main(void)
{
	rdiv_t negerr = {0}, poserr = {0};

	unsigned eseries = read_eseries();
	double resratio = read_ratio();
	double givenr2 = read_r2();

	calc_divs(givenr2, resratio, eseries, &negerr, &poserr);
	ausgabe(&negerr, &poserr);

	return 0;
}
