using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System; 
using System.Net.Http;
using System.Threading.Tasks;
using Medidata.MAuth.Core;

namespace NewC_
{
    public class NewClass419
    {
        static async Task Main(string[] args)
        {
            var mauthSigningHandler = new MAuthSigningHandler(
                new MAuthSigningOptions()
                {
                    ApplicationUuid = new Guid("Your application uuid goes here"),
                    PrivateKey = "Your private key contents or local path to the key file goes here"
                }
            );
 
            var client = new HttpClient(mauthSigningHandler);
             
            var request = new HttpRequestMessage(HttpMethod.Get, "https://api.mdsol.com/countries");
 
            request.Headers.Add("Accept", "application/json");
            request.Headers.Add("Mcc-Version", "v2019-04-12");
 
            var response = await client.SendAsync(request);
 
            response.EnsureSuccessStatusCode();
 
            Console.WriteLine("The response body is the following:");
            Console.WriteLine($"{await response.Content.ReadAsStringAsync()}");
 
            Console.WriteLine("\nPress ANY key to exit.");
            Console.ReadKey();
        }
    }
}


 
