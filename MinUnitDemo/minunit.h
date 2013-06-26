/*
 * minunit.h
 *
 *  Created on: Jun 25, 2013
 *      Author: Julian Brown
 */

#ifndef MINUNIT_H_
#define MINUNIT_H_

 /* file: minunit.h */
 #define mu_assert(message, test) do { if (!(test)) return message; } while (0)
 #define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)
 extern int tests_run;

#endif /* MINUNIT_H_ */
