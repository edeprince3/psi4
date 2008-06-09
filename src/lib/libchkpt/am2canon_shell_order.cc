/*! \defgroup CHKPT libchkpt: The Checkpoint Interface library */

/*!
  \file
  \ingroup CHKPT
*/

#include <cstdlib>
#include <psifiles.h>
#include <libpsio/psio.hpp>
#include <libchkpt/chkpt.h>
#include <libchkpt/chkpt.hpp>

namespace psi {

/*!
** int *Chkpt::rd_am2canon_shell_order()
**
** Reads in the mapping array from the am-ordered
** to the canonical (in the order of appearance)
** list of shells.
**
** Returns: int *am2can_shell_order
** \ingroup CHKPT
*/
int *Chkpt::rd_am2canon_shell_order(void)
{
	int *am2can_sh_ord, nshell;
	char *keyword;
	keyword = build_keyword("AM -> canonical shell map"); 

	nshell = rd_nshell();
	am2can_sh_ord = array<int>(nshell);

	psio->read_entry(PSIF_CHKPT, keyword, (char *) am2can_sh_ord,
		nshell*sizeof(int));

	free(keyword);
	return am2can_sh_ord;
}

/*!
** void Chkpt::wt_am2canon_shell_order()
**
** Writes out the mapping array from the am-ordered
** to the canonical (in the order of appearance)
** list of shells.
**
** \param am2can_shell_order = array to store the mapping array
**
** Returns: none
** \ingroup CHKPT 
*/
void Chkpt::wt_am2canon_shell_order(int *am2can_sh_ord)
{
	int nshell;
	char *keyword;
	keyword = build_keyword("AM -> canonical shell map");

	nshell = rd_nshell();

	psio->write_entry(PSIF_CHKPT, keyword, (char *) am2can_sh_ord,
		nshell*sizeof(int));

  free(keyword);
}

/*!
** int *chkpt_rd_am2canon_shell_order()
**
** Reads in the mapping array from the am-ordered
** to the canonical (in the order of appearance)
** list of shells.
**
** Returns: int *am2can_shell_order
** \ingroup CHKPT
*/
        int *chkpt_rd_am2canon_shell_order(void)
	{
		return _default_chkpt_lib_->rd_am2canon_shell_order();
	}

/*!
** void chkpt_wt_am2canon_shell_order()
**
** Writes out the mapping array from the am-ordered
** to the canonical (in the order of appearance)
** list of shells.
**
** \param am2can_shell_order = array to store the mapping array
**
** Returns: none
** \ingroup CHKPT
*/
	void chkpt_wt_am2canon_shell_order(int *am2can_sh_ord)
	{
		_default_chkpt_lib_->wt_am2canon_shell_order(am2can_sh_ord);
	}
}

