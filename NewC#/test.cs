using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace NewC_
{
    public class test
    {
        
    }
}


        ActionFunctionParams afp = (ActionFunctionParams) ThisObject;
        DataPoint dpACT = afp.ActionDataPoint;
        Subject curSUBJ = dpACT.Record.Subject;
        int curMatrix = dpACT.Record.SubjectMatrixID;
        string curFD = dpACT.Record.DataPage.Instance.Folder.OID;
        Instance curINS = dpACT.Record.Instance;
        string fmDS2 = "DS2";
        string flDS2YN = "DS2YN";

        string flEPOCH = "EPOCH";
        string flDS2GRP = "DS2GRP";

        int exist = 0;

        System.Collections.Generic.List<string> lst_folders = new System.Collections.Generic.List<string>()
        {
            "C1D1", "C1D15", "C1D8", "C1D22"
        }
        ;
        DataPage dpPC5 = curINS.DataPages.FindByFormOID("PC5");
        DataPoint dpDS2EPOCH = curSUBJ.Instances.FindByFolderOID("SCR") ?.DataPages.FindByFormOID(fmDS2) ?.MasterRecord.DataPoints.FindByFieldOID(flEPOCH);
        DataPoint dpDS2GRP = curSUBJ.Instances.FindByFolderOID("SCR") ?.DataPages.FindByFormOID(fmDS2) ?.MasterRecord.DataPoints.FindByFieldOID(flDS2GRP);
        if (lst_folders.Contains(curFD))
        {
            if (curFD == "C1D1" || curFD == "C1D15")
            {
                if (dpACT != null && dpACT.Active && dpACT.Data == "Y")
                {
                    if (dpDS2EPOCH != null && dpDS2EPOCH.Active && dpDS2EPOCH.Data == "1") exist = 1;
                }
            }
            else if (curFD == "C1D8" || curFD == "C1D22")
            {
                if (dpACT != null && dpACT.Active && dpACT.Data == "Y")
                {
                    if (dpDS2EPOCH != null && dpDS2EPOCH.Active && dpDS2EPOCH.Data == "1")
                    {
                        if (dpDS2GRP != null && dpDS2GRP.Active && dpDS2GRP.Data != string.Empty && dpDS2GRP.Data != "7" && dpDS2GRP.Data != "8" && dpDS2GRP.Data != "9") exist = 1;
                    }
                }
            }

            if (exist == 1)
            {
                if (dpPC5 == null)
                curINS.AddCRF(curSUBJ.CRFVersion.Forms.FindByOID("PC5"), curMatrix);
                if (dpPC5 != null && !dpPC5.Active) dpPC5.Active = true;
            }
            else
            {
                if (dpPC5 != null && dpPC5.Active) dpPC5.Active = false;
            }
        }

        return null;