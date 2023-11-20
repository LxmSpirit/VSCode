using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Medidata.MAuth.Core;
using Medidata.MAuth.Core.Models;




namespace NewC_
{
    public class NewClass123
    {

        public async Task<HttpResponseMessage> SignAndSendRequest(HttpRequestMessage request)
        {
            var signingHandler = new MAuthSigningHandler(new MAuthSigningOptions()
            {
                ApplicationUuid = new Guid("7c872d75-986b-4c61-bb17-f2569d42bfb0"),

                // The following can be either a path to the key file or the contents of the file itself
                PrivateKey = "ClientPrivateKey.pem",

                // Enumerations of signing protocols, if not provided defaults to `MAuthVersion.MWS`for sign-in.
                SignVersions = MAuthVersion.MWS | MAuthVersion.MWSV2
            });

            using (var client = new HttpClient(signingHandler))
            {
                return await client.SendAsync(request);
            }
        }

    }
}



